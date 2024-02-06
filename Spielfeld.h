#ifndef SPIELFELD_H
#define SPIELFELD_H
#include "Frage.h"

#include <array>

struct Spielfeld
{
    std::array<std::array<Frage, 5>, 5> fragen;
    std::vector<std::string> kategorien;
    void printLinesBetween(std::ostream& os)const;
    // Konstruktor
    Spielfeld(const std::vector<std::string>& kategorien);

    // Methoden
    void frageStreichen(int spalte, int zeile);
    std::string repraesentiereFeld() const;
    
};


#endif /* SPIELFELD_H */
