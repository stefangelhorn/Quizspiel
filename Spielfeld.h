#ifndef SPIELFELD_H
#define SPIELFELD_H
#include "Frage.h"

#include <array>
#include <map>
#include <vector>

struct Spielfeld
{
    std::array<std::array<Frage, 5>, 5> fragen;
    std::vector<std::string> kategorien;
    void printLinesBetween(std::ostream& os)const;

    /// @brief die map ordnet dem Index für die Kategroie die indizes der offenen Fragen zu
    std::map<int, std::vector<int>> offeneFragen() const;
    
    // Konstruktor
    Spielfeld(const std::vector<std::string>& kategorien);

    // Methoden
    void frageStreichen(int spalte, int zeile);
    std::string repraesentiereFeld() const;    
};

#endif /* SPIELFELD_H */
