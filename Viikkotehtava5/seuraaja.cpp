#include "Seuraaja.h"

Seuraaja::Seuraaja(std::string n) : nimi(n), next(nullptr) {}

std::string Seuraaja::getNimi() {
    return nimi;
}

void Seuraaja::paivitys(std::string viesti) {
    std::cout << nimi << " vastaanotti viestin: " << viesti << std::endl;
}
