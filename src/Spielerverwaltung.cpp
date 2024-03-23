#include "Spielerverwaltung.h"


bool Spielerverwaltung::spielerAnlegen(const SpielerDaten& spielername)
{
    for(const auto& s : spieler)
    {
        if(s.name == spielername)
        {
            std::cerr << "Spieler bereits vorhanden!\n";
            return false;
        }
    }
        spieler.emplace_back(spielername, 0);
        return true;
}

Spieler Spielerverwaltung::get_naechsten_spieler()
{
    activer_spieler_idx = (activer_spieler_idx + 1) % spieler.size(); 
    return spieler[activer_spieler_idx];
}

void Spielerverwaltung::aktualisiere_punkte(int punktzahl)
{
    spieler[activer_spieler_idx].punkte += punktzahl;
}