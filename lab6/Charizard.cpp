#include "Charizard.h"

// Implement a Charizard class, you can refer to Pikachu class

Charizard::Charizard(int hp, int attack, int defense, int specialAttack,
                     int specialDefense, int speed)
    : Pokemon(hp, attack, defense, specialAttack, specialDefense, speed) {
    // Initialize the default nickname
    this->nickname = "Dummy";
}

void Charizard::description() {
    // Descript this Pokemon
    cout << this->nickname << " is Charizard" << endl;
}