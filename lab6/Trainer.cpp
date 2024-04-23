#include "Trainer.h"

#include "Charizard.h"
#include "Mimikyu.h"
#include "Pikachu.h"

void Trainer::changePokemon(Pokemon* pokemon) {
    // Change the current Pokemon, but only Charizard is acceptable class
    //
    // Hint: You can use 'dynamic_cast<>()' to check whether it is the class you
    // want

    Charizard* charizard = dynamic_cast<Charizard*>(pokemon);
    Pikachu* pikachu = dynamic_cast<Pikachu*>(pokemon);
    Mimikyu* mimikyu = dynamic_cast<Mimikyu*>(pokemon);

    if (charizard != nullptr) {
        cout << "Trainer " << this->name << " changes Pokemon successfully";
        // this->pokemon = charizard;
    } else {
        if (pikachu != nullptr) {
            cout << "Trainer " << this->name << " can not use Pikachu";
        }
        if (mimikyu != nullptr) {
            cout << "Trainer " << this->name << " can not use Mimikyu";
        }
    }
}