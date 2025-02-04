#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    pankkitili(const std::string& omistaja);

    virtual ~pankkitili();

    double getBalance() const;

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
};

#endif
