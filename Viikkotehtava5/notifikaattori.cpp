#include "Notifikaattori.h"

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {}

void Notifikaattori::lisaa(Seuraaja* uusi) {
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::poista(Seuraaja* poistettava) {
    if (!seuraajat) return;

    if (seuraajat == poistettava) {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja* nykyinen = seuraajat;
    while (nykyinen->next && nykyinen->next != poistettava) {
        nykyinen = nykyinen->next;
    }

    if (nykyinen->next) {
        nykyinen->next = poistettava->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        std::cout << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(std::string viesti) {
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
