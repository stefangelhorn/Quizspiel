#ifndef KONSOLE_H
#define KONSOLE_H
#include "Spielfeld.h"
#include "Spieler.h"
#include "UI.h"

struct Konsole : public UI
{
    Spielfeld& spielfeld;
    std::vector<Spieler> spieler;
    Konsole(Spielfeld& _spielfeld, std::vector<Spieler>& _spieler) 
    : spielfeld(_spielfeld), spieler(_spieler){}
    
    virtual SpielerDaten getSpielerdaten() override;
    virtual bool spielStarten() override;
    virtual void zeigeSpielfeld(const Spielfeld&) override;
    virtual Frage getFrage(const Spielfeld&) override;
    virtual Antwort getAntwort(const Frage&, const Spieler&) override;
};

#endif /* KONSOLE_H */
