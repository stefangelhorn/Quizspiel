#ifndef KONSOLE_H
#define KONSOLE_H
#include "Spielfeld.h"
#include "Spieler.h"

struct Konsole
{
    Spielfeld& spielfeld;
    std::vector<Spieler> spieler;
    Konsole(Spielfeld& _spielfeld, std::vector<Spieler>& _spieler) 
    : spielfeld(_spielfeld), spieler(_spieler){}
};

#endif /* KONSOLE_H */
