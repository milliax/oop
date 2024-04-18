#include "Pokemon.h"

void Pokemon::info() {
    // Print out all the information about this Pokemon.

    // cout << "Nickname: " << this->nickname << endl;
    description();
    cout << "> hp: " << this->hp << endl;
    cout << "> attack: " << this->attack << endl;
    cout << "> defense: " << this->defense << endl;
    cout << "> specialAttack: " << this->specialAttack << endl;
    cout << "> specialDefense: " << this->specialDefense << endl;
    cout << "> speed: " << this->speed << endl;
    cout << endl;
}