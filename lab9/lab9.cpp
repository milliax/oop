#include <fstream>
#include <iostream>

#include "Graph.h"

using namespace std;

void readFile(const char* filename) {
    // read the input date from file
    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }

    int n, temp, a, b;
    int nodes_num, edge_num;
    file >> n;

    while (n--) {
        Graph graph;
        file >> nodes_num;

        while (nodes_num--) {
            file >> temp;
            // graph.nodes.emplace_back(temp);
            graph.addNode(temp);
        }

        file >> edge_num;

        while (edge_num--) {
            file >> a >> b >> temp;
            graph.addEdge(a, b, temp);
        }

        graph.dfs();
        graph.print_visited_order();

        cout << "[" << graph.getTotalLength() << "]" << endl;
    }
}

int main() {
    readFile("Sample_Input.txt");
    // readFile("Hidden_Input.txt");

    return 0;
}