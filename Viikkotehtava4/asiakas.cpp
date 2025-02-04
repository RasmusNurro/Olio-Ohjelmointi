#include "asiakas.h"
#include <iostream>

asiakas::asiakas(const std::string& nimi, double luottoRaja)
    : nimi(nimi),
    kayttotili(nimi),             // Pankkitili-luokan konstruktori
    luottotili(nimi, luottoRaja)  // Luottotili-luokan konstruktori
{
}

std::string asiakas::getNimi() const {
    return nimi;
}

void asiakas::showSaldo() const {
    std::cout << "Asiakas: " << nimi << std::endl;
    std::cout << "  Pankkitilin saldo: " << kayttotili.getBalance() << std::endl;
    std::cout << "  Luottotilin saldo: " << luottotili.getBalance() << std::endl;
}

bool asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool asiakas::tiliSiirto(double amount, asiakas& kohde) {
    if (amount <= 0) {
        return false;
    }
    if (!kayttotili.withdraw(amount)) {
        return false;
    }
    if (!kohde.kayttotili.deposit(amount)) {
        return false;
    }
    return true;
}
