#include "Game.h"

Game::Game(int maxNum) {
    maxNumber = maxNum;
    numOfGuesses = 0;

    srand(time(0));
    randomNumber = (rand() % maxNumber) + 1;

    std::cout << "PELIN KONSTRUKTORI: Olio alustettu maksimiluvulla " << maxNumber << std::endl;
}


Game::~Game() {
    std::cout << "PELIN PURKAJA: Olio poistettu muistista." << std::endl;
}

void Game::play() {
    int guess = 0;
    std::cout << "Peli konstruktoitu 1 - " << maxNumber << " numeron valilta" << std::endl;

    while (true) {
        std::cout << "Arvaa numero: ";
        std::cin >> guess;
        numOfGuesses++;

        if (guess == randomNumber) {
            std::cout << "Oikein! Numero oli " << randomNumber << std::endl;
            break;
        } else if (guess < randomNumber) {
            std::cout << "Liian pieni arvaus." << std::endl;
        } else {
            std::cout << "Liian suuri arvaus." << std::endl;
        }
    }

    std::cout << "Arvauksia tarvittiin yhteensa: " << numOfGuesses << std::endl;
}
