#include "Frage.h"

    /// @brief Hilfsfunktion zum Präsentieren der Antworten
    /// @param antworten 
    void printAnswers(const std::vector<Antwort>& antworten)
    {
        int index = 1;
        for(const auto& antwort : antworten)
        {
            std::cout << '<' << index++ << "> " << antwort.text << '\n';
        }
    }

    Frage::Frage(int _wert, const std::string& _text, std::vector<Antwort> _antworten)
    : wert(_wert), text(_text), antworten(_antworten){}

    void Frage::fragePraesentieren() const
    {
        std::cout << text << '\n';
        printAnswers(antworten);
        std::cout << '\n';
    }

    bool Frage::auswerten(int antwort)const
    {
        return (antworten[antwort-1].richtigeAntwort);
    }
