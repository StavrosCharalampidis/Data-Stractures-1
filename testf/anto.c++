// C++ code to implement the above approach

#include <bits/stdc++.h>
using namespace std;

// Link list Node Class
class Node {
public:
	int data;
	Node* prev;
	Node* next;

	// Constructor function
	Node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

// Function to print linked list
void print(Node* head)
{
	Node* temp = head;

	// Iterate until node is NOT NULL
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Function to push a node in DLL
void push(Node*& head, Node*& tail,
		int item)
{

	// DLL is empty
	if (tail == NULL) {

		Node* temp = new Node(item);
		tail = temp;
		head = temp;
	}

	// DLL is not empty
	else {
		Node* temp = new Node(item);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

// Function to find the nodes
// which have to be swapped
pair<Node*, Node*> find(Node*& head,
						int x, int y)
{
	Node* N1 = NULL;
	Node* N2 = NULL;
	Node* temp = head;

	// Traversing the list
	while (temp != NULL) {
		if (temp->data == x)
			N1 = temp;
		else if (temp->data == y)
			N2 = temp;
		temp = temp->next;
	}
	return make_pair(N1, N2);
}

// Function to swap the nodes
// consisting of x and y
void swap(Node*& head, Node*& tail,
		int x, int y)
{

	// Edge Cases
	if (head == NULL || head->next == NULL
		|| x == y)
		return;

	// Finding the Nodes
	pair<Node*, Node*> p = find(head, x, y);

	Node* Node1 = p.first;
	Node* Node2 = p.second;

	if (Node1 == head)
		head = Node2;
	else if (Node2 == head)
		head = Node1;
	if (Node1 == tail)
		tail = Node2;
	else if (Node2 == tail)
		tail = Node1;

	// Swapping Node1 and Node2
	Node* temp;
	temp = Node1->next;
	Node1->next = Node2->next;
	Node2->next = temp;

	if (Node1->next != NULL)
		Node1->next->prev = Node1;
	if (Node2->next != NULL)
		Node2->next->prev = Node2;

	temp = Node1->prev;
	Node1->prev = Node2->prev;
	Node2->prev = temp;

	if (Node1->prev != NULL)
		Node1->prev->next = Node1;
	if (Node2->prev != NULL)
		Node2->prev->next = Node2;
}

// Driver Code
int main()
{

	Node* head = NULL;
	Node* tail = NULL;

	int val = 0;
	for (int i = 0; i < 10; i++)
	{
		push(head, tail, i);
		val = i;
	}
	
	
	int X = 1, Y = val;

	cout << "Before Swapping: ";
	print(head);

	swap(head, tail, X, Y);
	cout << "After Swapping: ";
	print(head);

	return 0;
}
