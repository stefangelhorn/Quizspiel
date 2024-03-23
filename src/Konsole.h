#ifndef KONSOLE_H
#define KONSOLE_H
#include "Spielfeld.h"
#include "Spieler.h"
#include "UI.h"

struct Konsole : public UI
{
    Konsole(){}
    virtual SpielerDaten getSpielerdaten() override;
    virtual bool spielStarten() override;
    virtual void zeigeSpielfeld(const Spielfeld&) override;
    virtual Frage getFrage(Spielfeld&, const Spieler&) override;
    virtual Antwort getAntwort(const Frage&, const Spieler&) override;
    virtual void zeigeSpielstand(const Spielerverwaltung&)override;
    virtual void siegerehrung(const Spielerverwaltung&)const override;
};

#endif /* KONSOLE_H */
