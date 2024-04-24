#include "LinkedList.h"

LinkedList::~LinkedList()
{
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::push_back(int x)
{
	// TODO: Insert a node to the end of the linked list, the node's value is x.
}

void LinkedList::push_front(int x)
{
	// Insert a node to the front of the linked list, the node's value is x.

	if (!head) {
		head = new ListNode(x);
		return;
	}
	ListNode* temp = new ListNode(x);

	temp->next = head;
	head = temp;
}

void LinkedList::insert(int index, int x)
{
	// TODO: Insert a node to the linked list at position "index", the node's value is x. 
	//		 The index of the first node in the linked list is 0.
}

void LinkedList::remove(int index)
{
	// TODO: Remove the node with index "index" in the linked list.
}

void LinkedList::reverse()
{
	// TODO: Reverse the linked list.
}

void LinkedList::swap(int index1, int index2)
{
	if (index1 == index2) return;

	// TODO: Swap two nodes in the linked list
}

void LinkedList::print()
{
	// TODO: Print all the elements in the linked list in order.
}
