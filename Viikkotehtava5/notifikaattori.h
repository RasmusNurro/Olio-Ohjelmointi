#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori();
    void lisaa(Seuraaja* uusi);
    void poista(Seuraaja* poistettava);
    void tulosta();
    void postita(std::string viesti);
};

#endif
