#include "Konsole.h"

#include <algorithm>
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
    std::cin.ignore();
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

    return intInput;
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

Frage Konsole::getFrage(Spielfeld &spielfeld, const Spieler& spieler)
{
    std::cout << spieler.name << " am Zug:\n";
    zeigeSpielfeld(spielfeld);
    auto Kategorien = spielfeld.offeneFragen();
    std::vector<std::string> offeneKategorien{};
    std::vector<int> kategorieIndizes{};
    for (auto &[kategorie_idx, fragen_indices] : Kategorien)
    {
        if (!fragen_indices.empty())
        {
            offeneKategorien.push_back(spielfeld.kategorien[kategorie_idx]);
            kategorieIndizes.push_back(kategorie_idx);
        }
    }

    int kategoriewahl = kategorieIndizes[menu(offeneKategorien)];

    std::vector<int> fragen_werte;
    std::vector<int> fragen_indices;
    for (auto &frage_idx : Kategorien[kategoriewahl])
    {
        fragen_werte.push_back(spielfeld.fragen[kategoriewahl][frage_idx].wert);
        fragen_indices.push_back(frage_idx);
    }

    int fragewahl = fragen_indices[menu(fragen_werte)];
    spielfeld.fragen[kategoriewahl][fragewahl].frageGestellt = true;
    return spielfeld.fragen[kategoriewahl][fragewahl];
}

Antwort Konsole::getAntwort(const Frage & frage, const Spieler &spieler)
{
    std::cout << spieler.name << " - Deine Frage: " << frage.text << '\n';
    int gegebeneAntwort = menu(frage.antworten);
    return frage.antworten[gegebeneAntwort];
}

void Konsole::zeigeSpielstand(const Spielerverwaltung& verwaltung)
{
    for(const auto& spieler : verwaltung.getSpieler())
    {
        std::cout << "Name: " << spieler.name << "\tPunkte: " << spieler.punkte << '\n';
    }
    std::cout << '\n';
}

void Konsole::siegerehrung(const Spielerverwaltung& verwaltung) const
{
    auto spieler = verwaltung.getSpieler();
    std::sort(spieler.begin(), spieler.end(), [](const Spieler& a, const Spieler& b){return a.punkte > b.punkte;});

    std::cout << spieler[0].name << " hat gewonnen!\n";

    for(const auto& s : spieler)
    {
        std::cout << s.name << "\t" << s.punkte << " Punkte\n";   
    }
    std::cout << '\n';
}