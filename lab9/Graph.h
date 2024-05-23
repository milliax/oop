#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>

using namespace std;

struct Edge;

struct Node {
    int element;
    vector<Edge*> edges;
    int distance = -1;

    Node(int element) : element(element) {}
};

struct Edge {
    Node* node1;
    Node* node2;
    int length;

    Edge(Node* node1, Node* node2, int length)
        : node1(node1), node2(node2), length(length) {}
};

class Graph {
   private:
    vector<Node*> nodes;
    vector<Edge*> edges;

    vector<bool> vis;
    vector<int> visited_order;

    Node* findNode(int element);
    int findNodeIndex(Node* nodeToFind);
    void dfsVisit(Node*,int);

   public:
    Graph() = default;
    ~Graph();

    Node* addNode(int element);
    // Edge* addEdge(Node* node1, Node* node2, int length);
    Edge* addEdge(int node1, int node2, int length);

    void dfs();
    void print_visited_order();
    int getTotalLength();
};

#endif // __GRAPH_H__