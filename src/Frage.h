#ifndef FRAGE_H
#define FRAGE_H
#include <vector>

#include "Antwort.h"

struct Frage
{
    int wert;
    std::string text;
    std::vector<Antwort> antworten;
    bool frageGestellt = false;
    int auswerten(const Antwort& antwort)const;
    // Konstruktor
    Frage(int _wert, const std::string& _text, std::vector<Antwort> _antworten);
    Frage(){}
    // Methoden
    std::string fragePraesentieren() const;
};

#endif /* FRAGE_H */
