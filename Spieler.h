#ifndef SPIELER_H
#define SPIELER_H
#include <iostream>

struct Spieler
{
    std::string name;
    int punkte;
    Spieler(const std::string& _name, int _punkte);
};

#endif /* SPIELER_H */
