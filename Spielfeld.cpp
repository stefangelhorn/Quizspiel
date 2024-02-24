#include "Spielfeld.h"
#include <fstream>
#include <iomanip>
#include <sstream>

void datenEinlesen(const std::string& kategorie, std::array<std::array<Frage, 5>, 5> fragen, int spalte)
{
    std::ifstream file(kategorie + ".csv");
    if(!file.is_open())
    {
        std::cout << "Oeffnen der Datei " << kategorie << ".csv fehlgeschlagen!\n";
        return;
    }

    for(int zeile = 0; zeile < 5; zeile++)
    {
        std::string line;
        std::getline(file, line);
        int wert;
        std::string frage;
        std::string antwort1, antwort2, antwort3, antwort4;
        bool a1, a2, a3, a4;

        std::stringstream ss(line);
        ss >> wert;
        ss.ignore();
        std::getline(ss, frage, ';');
        std::getline(ss, antwort1, ';');
        ss >> a1;
        ss.ignore();
        std::getline(ss, antwort2, ';');
        ss >> a2;
        ss.ignore();
        std::getline(ss, antwort3, ';');
        ss >> a3;
        ss.ignore();
        std::getline(ss, antwort4, ';');
        ss >> a4;
        ss.ignore();

        Antwort aw1{antwort1, a1};
        Antwort aw2{antwort2, a2};
        Antwort aw3{antwort3, a3};
        Antwort aw4{antwort4, a4};

        fragen[spalte][zeile] = Frage{wert, frage, {aw1, aw2, aw3, aw4}};
    }    
}


Spielfeld::Spielfeld(const std::vector<std::string>& _kategorien) : kategorien(_kategorien)
{    
    int spalte = 0;
    for(const auto& kategorie : _kategorien)
    {
        datenEinlesen(kategorie, fragen, spalte++);
    }
}

    void Spielfeld::frageStreichen(int spalte, int zeile)
    {
        fragen[spalte][zeile].frageGestellt = true;
    }
    
    void Spielfeld::printLinesBetween(std::ostream& os) const
    {
        os << '|';
        for(int i = 0; i < 5; i++)
        {
            os << std::string(kategorien[i].size(), '-') << '|';
        }
        os << '\n';
    }

    std::string printCentered(int fieldwidth, int value)
    {
        std::string s(fieldwidth/2 - 1, ' ');
        s += std::to_string(value);
        std::string s2(fieldwidth - s.length(), ' ');
        s += s2;
        return s;
    }

    std::string printCentered(int fieldwidth)
    {
        std::string s(fieldwidth/2, ' ');
        s += 'X';
        std::string s2(fieldwidth - s.length(), ' ');
        s += s2;
        return s;
    }


    std::string Spielfeld::repraesentiereFeld() const
    {
        std::ostringstream oss;
        // Überschrift
        oss << '|';
        for(int i = 0; i < 5; i++)
        {
            oss << kategorien[i] << '|'; 
        }
        oss << '\n';

        // Abgrenzung zur ersten Zeile
        printLinesBetween(oss);

        for(int zeile = 0; zeile < 5; zeile++)
        {
            oss << '|';
            for(int spalte = 0; spalte < 5; spalte++)
            {
                oss << (fragen[spalte][zeile].frageGestellt? printCentered(kategorien[spalte].size()) : printCentered(kategorien[spalte].size(), fragen[spalte][zeile].wert)) << '|';
                // Ist die Frage bereits gestellt worden, dann soll das Feld mit einem X gefüllt werden, ansonsten der Wert der Frage.
            }
            oss << '\n';
            printLinesBetween(oss);
        }
        oss << "\n\n";
        return oss.str();
    }

    std::map<int, std::vector<int>> Spielfeld::offeneFragen() const
    {
        std::map<int, std::vector<int>> _offeneFragen;
    
        for(size_t i = 0; i < fragen.size(); i++)
        {
            _offeneFragen[i] = std::vector<int>{}; // Hier wird ein leerer Vector hinzugefügt
            for(size_t j = 0; j < fragen[i].size(); j++)
            {
                if(!fragen[i][j].frageGestellt)
                {
                    _offeneFragen[i].push_back(j);
                }
            }
        }
        return _offeneFragen;
    }

    bool Spielfeld::nochFragenVorhanden()const
    {
        auto offen = offeneFragen();
        for(const auto& [kategorie_idx, fragen_idx] : offen)
        {
            if(!fragen_idx.empty())
            {
                return true;
            }
        }
        return false;
    }