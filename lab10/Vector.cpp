#include "Vector.h"

void Vector::append(int element) {
    // Append an element to the vector
    vec.push_back(element);
}

void Vector::clear() {
    // Clear the vector
    vec.clear();
}

void Vector::print() const {
    // Print the elements of the vector
    for (const auto& element : vec) cout << element << " ";
    cout << endl;
}

void Vector::heapify(int n, int i) {
    int largest = i;
    // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && vec[l] > vec[largest]) largest = l;

    // If right child is larger than largest so far
    if (r < n && vec[r] > vec[largest]) largest = r;

    // If largest is not root
    if (largest != i) {
        swap(vec[i], vec[largest]);

        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}

void Vector::heapSort() {
    // Perform heap sort on the vector
    //
    // Note: You can add other function like 'heapify()' to do this sorting
    // algorithm

    int n = vec.size();

    // build tree
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(vec[0], vec[i]);

        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}