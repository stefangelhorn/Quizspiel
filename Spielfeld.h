#ifndef SPIELFELD_H
#define SPIELFELD_H
#include "Frage.h"

struct Spielfeld
{
    Frage fragen[5][5];
    std::vector<std::string> kategorien;
    void printLinesBetween()const;
    // Konstruktor
    Spielfeld(const std::vector<std::string>& kategorien);

    // Methoden
    void frageStreichen(int spalte, int zeile);
    void print() const;
    
};


#endif /* SPIELFELD_H */
