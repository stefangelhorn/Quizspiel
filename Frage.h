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

    // Konstruktor
    Frage(int _wert, const std::string& _text, std::vector<Antwort> _antworten);
    Frage(){}
    // Methoden
    void fragePraesentieren() const;
    bool auswerten(int antwort)const;

};

#endif /* FRAGE_H */
