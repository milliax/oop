#include <fstream>
#include <iostream>

#include "Time.h"

using namespace std;

Time time1, time2;
char op;
fstream input;
fstream output;

void readFile(const char* filename) {
    // Read the data from the txt file.
    // istream input;
    input.open(filename);
    output.open("Output.txt", ios::out);

    if (!input.is_open()) {
        cout << "File Not Found" << endl;
    }

    return;
}

int main() {
    readFile("Sample_Input.txt");

    if (!input.is_open() || !output.is_open()) {
        if (!input.is_open()) {
            cout << "Input File Not Found\n" << endl;  // "File Not Found
        }
        if (!output.is_open()) {
            cout << "Output File Not Found\n" << endl;  // "File Not Found
        }
        return 0;
    }

    while (input >> time1 >> op >> time2) {
        switch (op) {
            case '+':
                output << time1 + time2;
                break;
            case '-':
                output << time1 - time2;
                break;
            case '!':
                if (time1 != time2) {
                    output << "True" << endl;
                } else {
                    output << "False" << endl;
                }
                // output << (time1 != time2);
                break;
            case '=':
                if (time1 == time2) {
                    output << "True" << endl;
                } else {
                    output << "False" << endl;
                }
                // output << (time1 == time2);
                break;
        }
    }

    return 0;
}