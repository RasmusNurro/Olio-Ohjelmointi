#include <iostream>

using namespace std;
int game(int maxnum);

int main()
{
    int maxnum=0;
    int ArvaustenMaara=0;
    cout << "Maximi satunnainen numero: ";
    cin >> maxnum;
    ArvaustenMaara = game(maxnum);
    cout << "Arvauksia yhteensa : " << ArvaustenMaara << endl;

    return 0;
}

int game(int maxnum){
    int ArvaustenMaara=0;
    srand(time(0));
    int randomNum = (rand() % maxnum+1)+1;
    int x;
    cout << "Satunainnen numero on tehty" << endl;
    int Arvaustila = 0;
    while(Arvaustila == 0){
        cout << "Arvaus: ";
        cin >> x;
        if (x==randomNum){
            cout << "Arvasit oikein numero oli " << randomNum << endl;
            Arvaustila = 1;
        } else if (x<randomNum){
            cout << "Arvasit liian matalalle" << endl;
        } else if (x>randomNum){
            cout << "Arvasit liian korkealle" << endl;
        }
        ArvaustenMaara++;
    }
    return ArvaustenMaara;
}
