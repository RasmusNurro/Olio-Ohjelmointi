#ifndef ITALIALAINENKOKKI
#define ITALIALAINENKOKKI

#include "Kokki.h"

class ItalialainenKokki : public Kokki {
private:
    std::string Password = "pizza";
    int jauho;
    int vesi;
    int teePizza();

public:
    ItalialainenKokki(std::string);
    ~ItalialainenKokki();
    bool askSecret(std::string, int, int);
};

#endif // ITALIALAINENKOKKI
