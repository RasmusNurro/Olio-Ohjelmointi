#include "Kokki.h"
#include "ItalialainenKokki.h"

int main() {
    Kokki chef1("Gordon");
    chef1.teeSalaatti(10);
    chef1.teeSoppa(12);

    ItalialainenKokki italianChef("Mario");
    italianChef.teeSalaatti(9);
    italianChef.teeSoppa(15);

    italianChef.askSecret("pizza", 20, 15);

    return 0;
}
