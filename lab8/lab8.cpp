#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BinarySearchTree.h"

using namespace std;

void readFile(const char* filename) {
    ifstream input(filename);
    stringstream ss;

    string line;

    int numTestcase, value;

    getline(input, line);
    // cin >> numTestcase;
    // cin.ignore();

    ss.str("");
    ss.clear();
    ss << line;
    ss >> numTestcase;

    while (numTestcase--) {
        getline(input, line);

        ss.str("");
        ss.clear();
        ss << line;

        BinarySearchTree tree;

        while (ss >> value) {
            TreeNode* node = new TreeNode(value);
            tree.insert(node);
        }

        TreeNode* root = tree.getRoot();

        cout << "preorder: ";
        tree.preorder(root);
        cout << endl;

        cout << "inorder: ";
        tree.inorder(root);
        cout << endl;

        cout << "postorder: ";
        tree.postorder(root);
        cout << endl;

        // tree.print_tree(root);

        cout << endl;
    }
}

int main() {
    readFile("Sample_Input.txt");
    // readFile("Hidden_Input.txt");

    return 0;
}