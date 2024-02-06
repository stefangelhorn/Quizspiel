#include "Konsole.h"

#include <iostream>
#include <string>

    SpielerDaten Konsole::getSpielerdaten()
    {
        SpielerDaten name;
        std::cout << "Name: ";
        std::getline(std::cin, name);
        return name;
    }

    bool Konsole::spielStarten()
    {
        std::cout << "Spiel starten? (j/n): ";
        char input;
        std::cin >> input;
        return (input == 'j'? true : false);
    }

    void Konsole::zeigeSpielfeld(const Spielfeld& spielfeld)
    {
        std::cout << spielfeld.repraesentiereFeld();
    }

/*
    virtual Frage Konsole::getFrage(const Spielfeld&) override;
    virtual Antwort Konsole::getAntwort(const Frage&, const Spieler&) override;
*/

/*
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
//*/
