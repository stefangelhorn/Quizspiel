#include "Frage.h"

#include <sstream>

    /// @brief Hilfsfunktion zum Präsentieren der Antworten
    /// @param antworten 
    void printAnswers(const std::vector<Antwort>& antworten, std::ostream& os)
    {
        int index = 1;
        for(const auto& antwort : antworten)
        {
            os << '<' << index++ << "> " << antwort.text << '\n';
        }
    }

    Frage::Frage(int _wert, const std::string& _text, std::vector<Antwort> _antworten)
    : wert(_wert), text(_text), antworten(_antworten){}

    std::string Frage::fragePraesentieren() const
    {
        std::ostringstream oss;
        oss << text << '\n';
        printAnswers(antworten, oss);
        oss << '\n';
        return oss.str();
    }

    bool Frage::auswerten(int antwort)const
    {
        return (antworten[antwort-1].richtigeAntwort);
    }
