#include "Kokki.h"

Kokki::Kokki(std::string KokinNimi) {
    std::cout << "Kokki" << KokinNimi << "konstruktori" << std::endl;
}


Kokki::~Kokki() {
    std::cout << "Kokki" << KokinNimi << "destruktori" << std::endl;
}

int Kokki::teeSalaatti(int SalaattiAinekset){
    std::cout << "Valmistetaan" << SalaattiAinekset / 5 << "Annosta" << std::endl;
    return SalaattiAinekset / 5;
}


int Kokki::teeSoppa (int SoppaAinekset){
    std::cout << "Valmistetaan" << SoppaAinekset / 3 << "Annosta soppaa yum" << std::endl;
    return SoppaAinekset / 3;
}
