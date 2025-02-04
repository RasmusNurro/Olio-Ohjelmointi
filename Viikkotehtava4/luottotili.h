#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"
#include <string>

class luottotili : public pankkitili {
protected:
    double luottoRaja;

public:
    luottotili(const std::string& omistaja, double luottoRaja);

    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};

#endif
