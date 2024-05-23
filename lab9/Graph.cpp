#include "Graph.h"

Graph::~Graph() {
    // OPTIONAL: delete all allocated memory

    for (auto e : edges) {
        delete e;
    }

    for (auto e : nodes) {
        delete e;
    }
}

Node* Graph::findNode(int element) {
    for (int i = 0; i < nodes.size(); i++) {
        if (this->nodes[i]->element == element) return this->nodes[i];
    }
    return nullptr;
}

int Graph::findNodeIndex(Node* nodeToFind) {
    for (int i = 0; i < nodes.size(); i++) {
        if (this->nodes[i] == nodeToFind) return i;
    }
    return -1;
}

Node* Graph::addNode(int element) {
    // TODO: Add a new node and return it.
    //       If the element already exists, return the node.
    //
    // NOTE: Assume all the elements are unique.

    // Node* node = findNode(element);
    Node* newNode = new Node(element);

    while (vis.size() <= element) {
        vis.emplace_back(false);
    }

    nodes.emplace_back(newNode);

    // cout << "New Node: " << newNode->element << endl;

    return newNode;
}

Edge* Graph::addEdge(int node1, int node2, int length) {
    // TODO: Add two nodes as a new edge if both nodes are in the graph.
    //       Otherwise, return nullptr.
    //
    // NOTE: The direction is from node1 to node2.
    //       Remember to link the node with edge, it will be helpful when doing
    //       the traverse.

    Node* n1 = findNode(node1);
    Node* n2 = findNode(node2);

    Edge* newEdge = new Edge(n1, n2, length);

    edges.emplace_back(newEdge);

    // cout << "New Edge length: " << newEdge->length << ", n1: " << n1->element
    //      << ", n2: " << n2->element << endl;

    return newEdge;
}

void Graph::dfs() {
    // Use Depth-First Search to traverse the graph.
    //
    // NOTE: Start from the first added node.
    //       If there are other nodes that are not connected, ignore them.
    //
    // Hint: You can use 'vector<bool>' to record whether the node has visited.
    //       You can use 'stack<Node*>' to traverse the graph, or you can also
    //       create your own function to recursive such as 'void
    //       Graph::dfsVisit(Node*, vector<bool>&)'.

    dfsVisit(edges[0]->node1, 0);

    return;
}

void Graph::dfsVisit(Node* node, int accumulated_length) {
    if (vis[node->element]) {
        return;  // visited
    }

    vis[node->element] = true;
    visited_order.emplace_back(node->element);
    node->distance = accumulated_length;
    // cout << "Visit: " << node->element << endl;

    for (auto e : edges) {
        if (e->node1->element == node->element) {
            // cout << "A route found" << endl;

            dfsVisit(e->node2, e->length + accumulated_length);
        }
    }

    return;
}

int Graph::getTotalLength() {
    // Return the total lengths of all edges in the graph.
    //
    // NOTE: Start from the first added node.
    //       If there are other nodes that are not connected, ignore them.

    int max_length = -1;

    for (auto node : nodes) {
        if (node->distance > max_length) {
            max_length = node->distance;
        }
    }

    return max_length;
}

void Graph::print_visited_order() {
    for(auto e : nodes){
        cout << "Node: " << e->element << ", distance: " << e->distance << endl;
    }

    cout << "[";
    for (int i = 0; i < visited_order.size(); ++i) {
        cout << visited_order[i];
        if (i != (visited_order.size() - 1)) {
            cout << " ";
        }
    }
    cout << "] ";
}