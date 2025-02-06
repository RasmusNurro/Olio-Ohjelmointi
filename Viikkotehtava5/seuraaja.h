#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
#include <string>

class Seuraaja {
public:
    std::string nimi;
    Seuraaja* next;

    Seuraaja(std::string n);
    std::string getNimi();
    void paivitys(std::string viesti);
};

#endif
