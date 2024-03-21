#include <fstream>
#include <iostream>

#include "DateCalculator.h"

using namespace std;

int main() {
    DateCalculator calculator;
    calculator.readFile("Sample_Input.txt");
    // calculator.readFile("Hidden_Input.txt");

    while(!calculator.is_finish()){
        calculator.count();
        calculator.showDay();
        calculator.next();
    }
    return 0;
}