#ifndef SPIELERVERWALTUNG_H
#define SPIELERVERWALTUNG_H
#include "Spieler.h"
#include <vector>

typedef std::string SpielerDaten;

class Spielerverwaltung {
  std::vector<Spieler> spieler;
  int activer_spieler_idx = 0;

  public:
  Spielerverwaltung() {}

  Spieler get_naechsten_spieler();
  bool spielerAnlegen(const SpielerDaten &);
  void aktualisiere_punkte(int punktzahl);
  const std::vector<Spieler>& getSpieler()const{return spieler;}
};

#endif /* SPIELERVERWALTUNG_H */
