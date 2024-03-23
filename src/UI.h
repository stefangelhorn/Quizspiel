#ifndef UI_H
#define UI_H
#include "Antwort.h"
#include "Frage.h"
#include "Spieler.h"
#include "Spielfeld.h"
#include "Spielerverwaltung.h"

#include <iostream>
struct UI
{
    virtual SpielerDaten getSpielerdaten() = 0;
    virtual bool spielStarten() = 0;
    virtual void zeigeSpielfeld(const Spielfeld&) = 0;
    virtual Frage getFrage(Spielfeld&, const Spieler&) = 0;
    virtual Antwort getAntwort(const Frage&, const Spieler&) = 0;
    virtual void zeigeSpielstand(const Spielerverwaltung&)=0;
    virtual void siegerehrung(const Spielerverwaltung&)const = 0;
};

#endif /* UI_H */
