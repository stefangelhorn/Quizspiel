#include "Konsole.h"

int main()
{
    Spielfeld spielfeld{{"Sport", "Unterhaltung", "Geschichte", "Film", "Politik"}};    
    std::vector<Spieler> spieler{{"Stefan", 0}};
    Konsole console{spielfeld, spieler};

    std::cout << spielfeld.repraesentiereFeld();

    std::cout << spielfeld.fragen[2][3].fragePraesentieren();

    return 0;
}