#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    int maxNumber;
    int randomNumber;
    int numOfGuesses;

public:
    Game(int maxNum);
    ~Game();
    void play();
};

#endif
