#include "Konsole.h"
#include "Spielerverwaltung.h"
#include "UI.h"

int main()
{
  Spielfeld spielfeld{
      {"Sport", "Unterhaltung", "Geschichte", "Film", "Politik"}};
  Konsole console;
  UI *ui = &console;
  Spielerverwaltung verwaltung;

  do
  {
    auto spielerdaten = ui->getSpielerdaten();
    verwaltung.spielerAnlegen(spielerdaten);
  } while (!ui->spielStarten());

  while (spielfeld.nochFragenVorhanden())
  {
    auto aktiverSpieler = verwaltung.get_naechsten_spieler();
    auto frage = ui->getFrage(spielfeld, aktiverSpieler);
    auto antwort = ui->getAntwort(frage, aktiverSpieler);
    auto punkt_aenderung = frage.auswerten(antwort);
    verwaltung.aktualisiere_punkte(punkt_aenderung);
    ui->zeigeSpielstand(verwaltung);
  }

  

  return 0;
}