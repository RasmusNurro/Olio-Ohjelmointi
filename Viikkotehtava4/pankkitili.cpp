#include "Pankkitili.h"

pankkitili::pankkitili(const std::string& omistaja)
    : omistaja(omistaja), saldo(0.0)
{
}


pankkitili::~pankkitili()
{
}

double pankkitili::getBalance() const {
    return saldo;
}

bool pankkitili::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    saldo += amount;
    return true;
}

bool pankkitili::withdraw(double amount) {
    if (amount < 0) {
        return false;
    }
    if (amount > saldo) {
        return false;
    }
    saldo -= amount;
    return true;
}
