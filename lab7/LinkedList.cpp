#include "LinkedList.h"

LinkedList::~LinkedList() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::push_back(int x) {
    // Insert a node to the end of the linked list, the node's value is x.

    if (!head) {
        head = new ListNode(x);
        return;
    }

    ListNode* ptr = head;
    ListNode* temp = new ListNode(x);

    while (ptr->next) {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void LinkedList::push_front(int x) {
    // Insert a node to the front of the linked list, the node's value is x.

    if (!head) {
        head = new ListNode(x);
        return;
    }
    ListNode* temp = new ListNode(x);

    temp->next = head;
    head = temp;
}

void LinkedList::insert(int index, int x) {
    // Insert a node to the linked list at position "index", the node's
    // value is x.
    //		 The index of the first node in the linked list is 0.

    if (index == 0) {
        ListNode* ptr = head;
        head = new ListNode(x);
        head->next = ptr;

        return;
    }

    ListNode* last_node = head;

    for (int i = 0; i < index - 1; ++i) {
        last_node = last_node->next;
        // ptr = ptr->next;
    }

    ListNode* newNode = new ListNode(x);
    ListNode* next_node = last_node->next;

    last_node->next = newNode;
    newNode->next = next_node;

    return;
}

void LinkedList::remove(int index) {
    // Remove the node with index "index" in the linked list.

    if (index == 0) {
        if (head->next) {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
        } else {
            delete head;
            head = nullptr;
        }

        return;
    }

    ListNode* ptr = head;
    ListNode* pre_node = head;

    for (int i = 0; i < index; ++i) {
        pre_node = ptr;
        ptr = ptr->next;
    }

    ListNode* next_node = ptr->next;
    delete ptr;
    pre_node->next = next_node;

    return;
}

void LinkedList::reverse() {
    // Reverse the linked list.

    // get length
    ListNode* ptr = head;
    ListNode* last_node = head;

    if (head == nullptr) {
        return;
    }

    int length = 1;

    while (ptr->next) {
        ptr = ptr->next;
        length++;
        last_node = ptr;
    }

    for (int i = 0; i < length / 2; ++i) {
        swap(i, length - i - 1);
    }
}

void LinkedList::swap(int index1, int index2) {
    if (index1 == index2) return;

    if (index1 > index2) {
        int temp = index1;
        index1 = index2;
        index2 = temp;
        return;
    }

    // Swap two nodes in the linked list

    ListNode* ptrA = head;
    ListNode* ptrB = head;

    // index1 < index2

    for (int i = 0; i < index2; ++i) {
        if (index1 > i) {
            ptrA = ptrA->next;
        }

        ptrB = ptrB->next;
    }

    int tmp;
    tmp = ptrA->val;
    ptrA->val = ptrB->val;
    ptrB->val = tmp;

    return;
}

void LinkedList::print() {
    // Print all the elements in the linked list in order.
    ListNode* ptr = head;

    if (ptr == nullptr) {
        cout << "[]" << endl;
        return;
    }

    bool is_last = false;

    cout << "[" << ptr->val << " ";
    while (ptr->next) {
        ptr = ptr->next;

        if (ptr->next == nullptr) {
            is_last = true;
        }

        if (is_last) {
            cout << ptr->val;
        } else {
            cout << ptr->val << " ";
        }
    }

    cout << "]" << endl;
}
