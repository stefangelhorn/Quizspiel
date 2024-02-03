#ifndef ANTWORT_H
#define ANTWORT_H
#include <iostream>

struct Antwort
{
    const std::string text;
    bool richtigeAntwort;
    Antwort(const std::string& _text, bool _richtigeAntwort);
};

#endif /* ANTWORT_H */
