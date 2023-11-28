#include <iostream>

template <typename T>
class S_Node
{
public:
    T data;
    S_Node *next;

    S_Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
void addDescending(S_Node<T> **head, T value)
{
    S_Node<T> *newNode = new S_Node<T>(value);

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    if ((*head)->data <= value)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    S_Node<T> *current = *head;
    while (current->next != nullptr && current->next->data > value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
template <typename T>
void disp(S_Node<T> *head){
    S_Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}
// Example usage:
int main()
{
    S_Node<int> *head = nullptr;

    addDescending(&head, 10);
    addDescending(&head, 5);
    addDescending(&head, 8);
    addDescending(&head, 12);

    // Display the linked list
    disp(head);

    return 0;
}