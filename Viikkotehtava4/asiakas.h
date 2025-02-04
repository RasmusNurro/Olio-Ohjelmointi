#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>
#include "pankkitili.h"
#include "luottotili.h"

class asiakas {
private:
    std::string nimi;
    pankkitili kayttotili;
    luottotili luottotili;

public:
    asiakas(const std::string& nimi, double luottoRaja);
    std::string getNimi() const;
    void showSaldo() const;
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, asiakas& kohde);
};

#endif
