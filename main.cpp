#include "Konsole.h"

int main()
{
    Spielfeld spielfeld{{"Sport", "Unterhaltung", "Geschichte", "Film", "Politik"}};    
    std::vector<Spieler> spieler{{"Stefan", 0}};
    Konsole console{spielfeld, spieler};

    spielfeld.print();

    spielfeld.fragen[2][3].fragePraesentieren();

    return 0;
}