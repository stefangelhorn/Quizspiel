#include "Konsole.h"

#include <cctype>
#include <iostream>
#include <string>

SpielerDaten Konsole::getSpielerdaten()
{
    SpielerDaten name;
    std::cout << "Name: ";
    std::getline(std::cin, name);
    return name;
}

bool Konsole::spielStarten()
{
    std::cout << "Spiel starten? (j/n): ";
    char input;
    std::cin >> input;
    return (input == 'j' ? true : false);
}

void Konsole::zeigeSpielfeld(const Spielfeld &spielfeld)
{
    std::cout << spielfeld.repraesentiereFeld();
}

int safeIntInput(int lower, int upper)
{
    bool korrekt;
    std::string input;
    int intInput;
    do
    {
        korrekt = true;
        std::cout << "Bitte zwischen " << lower << " und " << upper << " waehlen: ";
        std::cin >> input;
        for (const char c : input)
        {
            if (!isdigit(c))
            {
                korrekt = false;
            }
        }
        if (korrekt)
        {
            intInput = std::stoi(input);
        }
    } while (!korrekt || intInput < lower || intInput > upper);
}

template <typename T>
int menu(const std::vector<T> &menupunkte)
{
    int index = 0;
    for (const auto &punkt : menupunkte)
    {
        std::cout << '<' << ++index << "> " << punkt << '\n';
    }
    return safeIntInput(1, index) - 1;
}

Frage Konsole::getFrage(const Spielfeld &spielfeld)
{
    zeigeSpielfeld(spielfeld);
    auto Kategorien = spielfeld.offeneFragen();
    std::vector<std::string> offeneKategorien{};
    for (auto &[kategorie_idx, fragen_indices] : Kategorien)
    {
        if (!fragen_indices.empty())
        {
            offeneKategorien.push_back(spielfeld.kategorien[kategorie_idx]);
        }
    }
    int kategoriewahl = menu(offeneKategorien);

    std::vector<int> fragen_werte;
    for (auto &frage_idx : Kategorien[kategoriewahl])
    {
        fragen_werte.push_back(spielfeld.fragen[kategoriewahl][frage_idx].wert);
    }

    int fragewahl = menu(fragen_werte);
    return spielfeld.fragen[kategoriewahl][fragewahl];
}

Antwort Konsole::getAntwort(const Frage & frage, const Spieler &spieler)
{
    std::cout << "Frage: " << frage.text << '\n';
    int gegebeneAntwort = menu(frage.antworten);
    return frage.antworten[gegebeneAntwort];
}

/*
    virtual Frage Konsole::getFrage(const Spielfeld&) override;
    virtual Antwort Konsole::getAntwort(const Frage&, const Spieler&) override;
*/

/*
struct Konsole : public UI
{
    Spielfeld& spielfeld;
    std::vector<Spieler> spieler;
    Konsole(Spielfeld& _spielfeld, std::vector<Spieler>& _spieler)
    : spielfeld(_spielfeld), spieler(_spieler){}

    virtual SpielerDaten getSpielerdaten() override;
    virtual bool spielStarten() override;
    virtual void zeigeSpielfeld(const Spielfeld&) override;
    virtual Frage getFrage(const Spielfeld&) override;
    virtual Antwort getAntwort(const Frage&, const Spieler&) override;
};
//*/
