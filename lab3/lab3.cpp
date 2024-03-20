#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ConnectFour.h"

using namespace std;

int main() {
    vector<int> chess_places;
    int temp;
    int step;
    // Read the input from the "Sample_Input.txt" file
    string line;
    ifstream rfile;
    stringstream buffer;
    rfile.open("Sample_Input.txt");

    // skipped checking rfile is open
    getline(rfile, line);
    buffer << line;
    int n;  // Read the number of games from file
    buffer >> n;

    cout << n << endl;

    while (n--) {
        ConnectFour connectFour;
        step = 0;
        getline(rfile, line);

        buffer.str(string());
        buffer.clear();
        buffer << line;
        chess_places.clear();

        while (buffer >> temp) {
            chess_places.emplace_back(temp);
        }

        // cout << "chess number: " << chess_places.size() << endl;

        // Play Connect Four
        do {
            connectFour.Place(step, chess_places[step] - 1);
            step++;
        // } while (step < 42);
        } while (connectFour.GetGameStatus() == Playing && step < 42);

        // Print the result
        connectFour.PrintBoard();
        connectFour.PrintWinner();
        cout << endl;
    }

    return 0;
}