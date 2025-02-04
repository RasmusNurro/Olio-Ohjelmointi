#include "luottotili.h"

luottotili::luottotili(const std::string& omistaja, double luottoRaja)
    : pankkitili(omistaja), luottoRaja(luottoRaja)
{
}

bool luottotili::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    if (saldo + amount > 0) {
        return false;
    }
    saldo += amount;
    return true;
}

bool luottotili::withdraw(double amount) {
    if (amount < 0) {
        return false;
    }
    if (saldo - amount < -luottoRaja) {
        return false;
    }
    saldo -= amount;
    return true;
}
