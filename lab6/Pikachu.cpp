#include "Pikachu.h"

Pikachu::Pikachu(int hp, int attack, int defense, int specialAttack,
                 int specialDefense, int speed)
    : Pokemon(hp, attack, defense, specialAttack, specialDefense, speed) {
    // Initialize the default nickname
    this->nickname = "Pikachu";
}

void Pikachu::description() {
    // Descript this Pokemon
    cout << this->nickname << " is Pikachu" << endl;
}