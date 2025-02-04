#include <iostream>
#include "asiakas.h"

int main() {

    std::cout << "Poipssipds" << std::endl;
    asiakas asiakas1("Matti", 1000.0);
    asiakas asiakas2("Maija", 500.0);

    asiakas1.talletus(300);
    asiakas1.showSaldo();
    std::cout << std::endl;

    asiakas2.talletus(100);
    asiakas2.showSaldo();
    std::cout << std::endl;

    if (asiakas1.tiliSiirto(200, asiakas2)) {
        std::cout << "Tilisiirto Matilta Maijalle onnistui." << std::endl;
    } else {
        std::cout << "Tilisiirto Matilta Maijalle epäonnistui." << std::endl;
    }
    std::cout << std::endl;

    asiakas1.showSaldo();
    std::cout << std::endl;
    asiakas2.showSaldo();

    return 0;
}
