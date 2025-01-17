#include "Game.h"

int main() {
    int maxNumber;
    std::cout << "Maximi satunnainen numero: ";
    std::cin >> maxNumber;

    Game game(maxNumber);
    game.play();

    return 0;
}
