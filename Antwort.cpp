#include "Antwort.h"

    Antwort::Antwort(const std::string& _text, bool _richtigeAntwort)
    : text(_text), richtigeAntwort(_richtigeAntwort){}

    std::ostream& operator<<(std::ostream& os, const Antwort& antwort)
    {
        return os << antwort.text;
    }