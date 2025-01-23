#include "ItalialainenKokki.h"

ItalialainenKokki::ItalialainenKokki(std::string KokinNimi) : Kokki(KokinNimi), jauho(0), vesi(0){
    std::cout << "Italialainen Kokki" << KokinNimi << "konstruktori" << std::endl;
}


ItalialainenKokki::~ItalialainenKokki() {
    std::cout << "Italialainen Kokki" << KokinNimi << "destruktori" << std::endl;
}

bool ItalialainenKokki::askSecret(std::string salasana, int vedenmaara, int jauhomaara){
    if(salasana==Password){
        jauho = jauhomaara;
        vesi = vedenmaara;
        int maara = teePizza();
        std::cout << "Tehty " << maara << " pizzoja." << std::endl;
        return true;
    }
    else{
        std::cout << "Vaara salasana." << std::endl;
        return false;
    }
}

int ItalialainenKokki::teePizza(){
    int maximijauho = jauho / 5;
    int maximivesi = vesi / 5;
    int mahdollisetpizzat;
    if(maximivesi<maximijauho){
        mahdollisetpizzat = maximivesi;
    } else {
        mahdollisetpizzat = maximijauho;
    }
    return mahdollisetpizzat;
}
