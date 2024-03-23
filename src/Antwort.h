#ifndef ANTWORT_H
#define ANTWORT_H
#include <iostream>

struct Antwort {
  const std::string text;
  bool richtigeAntwort;
  Antwort(const std::string &_text, bool _richtigeAntwort);
};

std::ostream &operator<<(std::ostream &os, const Antwort &antwort);

#endif /* ANTWORT_H */
