#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "LinkedList.h"

using namespace std;

#define OP_PUSH_BACK 'b'
#define OP_PUSH_FRONT 'f'
#define OP_INSERT 'i'
#define OP_REMOVE 'd'
#define OP_REVERSE 'r'
#define OP_SWAP 's'

void readFile(const char* filename) {
    ifstream input(filename);
    stringstream ss;

    if (!input.is_open()) {
        cout << "File Not Found" << endl;
        return;
    }

    string line;

    char op;
    int value, index1, index2;

    while (getline(input, line)) {
        LinkedList list;

        ss.str("");
        ss.clear();
        ss << line;

        // cout << "A try" << endl << endl;
        while (ss >> op) {
            switch (op) {
                case OP_PUSH_BACK:
                    ss >> value;
                    // cout << "PUSH BACK " << value << endl;
                    list.push_back(value);
                    break;
                case OP_PUSH_FRONT:
                    ss >> value;
                    // cout << "FRONT " << value << endl;
                    list.push_front(value);
                    break;
                case OP_INSERT:
                    ss >> index1 >> value;
                    // cout << "INSERT " << index1 << " " << value << endl;
                    list.insert(index1, value);
                    break;
                case OP_REMOVE:
                    ss >> index1;
                    // cout << "REMOVE " << index1 << endl;
                    list.remove(index1);
                    break;
                case OP_REVERSE:
                    // cout << "REVERSE" << endl;
                    list.reverse();
                    break;
                case OP_SWAP:
                    ss >> index1 >> index2;
                    // cout << "SWAP " << index1 << " " << index2 << endl;
                    list.swap(index1, index2);
                    break;
                default:
                    break;
            }
            // list.print();
        }

        list.print();
    }

    

    return;
}

int main() {
    // readFile("Sample_Input.txt");
    readFile("Hidden_Input.txt");

    return 0;
}