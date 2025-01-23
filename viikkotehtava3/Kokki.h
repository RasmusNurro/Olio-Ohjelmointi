#ifndef KOKKI_H
#define KOKKI_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Kokki {
protected:
    std::string KokinNimi;

public:
    Kokki(std::string);
    ~Kokki();
    std::string saaNimi();
    int teeSalaatti(int SalaattiAinekset);
    int teeSoppa(int SoppaAinekset);
};

#endif
