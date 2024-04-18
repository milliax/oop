#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Charizard.h"
#include "Mimikyu.h"
#include "Pikachu.h"
#include "Pokemon.h"
#include "Trainer.h"
using namespace std;
int main() {
    // Read the data from the txt file.

    fstream rfile;
    // rfile.open("Sample_Input.txt", ios::in);
    rfile.open("Hidden_Input.txt", ios::in);

    string pokemonType, nickname, tempString;
    int hp, attack, defense, specialAttack, specialDefense, speed;
    int ptr = 0;

    vector<Pokemon*> pokemons;

    getline(rfile, tempString);
    int n = stoi(tempString);
    for (int i = 0; i < n; ++i) {
        getline(rfile, tempString);
        string deliminator = ", ";
        pokemonType = tempString.substr(0, tempString.find(deliminator));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        nickname = tempString.substr(0, tempString.find(deliminator));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        hp = stoi(tempString.substr(0, tempString.find(deliminator)));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        attack = stoi(tempString.substr(0, tempString.find(deliminator)));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        defense = stoi(tempString.substr(0, tempString.find(deliminator)));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        specialAttack =
            stoi(tempString.substr(0, tempString.find(deliminator)));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        specialDefense =
            stoi(tempString.substr(0, tempString.find(deliminator)));
        tempString.erase(0,
                         tempString.find(deliminator) + deliminator.length());
        speed = stoi(tempString);

        if (pokemonType == "Pikachu") {
            Pokemon* pikachu = new Pikachu(hp, attack, defense, specialAttack,
                                           specialDefense, speed);
            pikachu->setNickname(nickname);
            pikachu->info();
            // pikachu->description();
            pokemons.emplace_back(pikachu);
        } else if (pokemonType == "Mimikyu") {
            Pokemon* mimikyu = new Mimikyu(hp, attack, defense, specialAttack,
                                           specialDefense, speed);
            mimikyu->setNickname(nickname);
            mimikyu->info();
            pokemons.emplace_back(mimikyu);
        } else if (pokemonType == "Charizard") {
            Pokemon* charizard = new Charizard(
                hp, attack, defense, specialAttack, specialDefense, speed);
            charizard->setNickname(nickname);
            charizard->info();
            pokemons.emplace_back(charizard);
        }
    }

    // Create the Pokemon according to the input file.
    //   1. Create the Pokemon.
    //   2. Print out the infomation.
    //   3. Print out the description.
    //
    // Example:
    //

    // Pokemon* pikachu = new Pikachu(pikachu 'hp, pikachu' attack,
    //                                pikachu 'defense,  pikachu' specialAttack,
    //                                pikachu 'specialDefense,  pikachu' speed);
    // pikachu->setNickname(pikachu'nickname);
    // pikachu->info();
    // pikachu->description();
    // cout << endl;

    Trainer* trainer = new Trainer("Red");

    for (auto p : pokemons) {
        trainer->changePokemon(p);
        cout << endl;
    }

    return 0;
}