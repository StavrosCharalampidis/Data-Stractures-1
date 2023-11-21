#include <stdio.h>
#include <stdlib.h>

// Link list Node Structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to print linked list
void print(struct Node* head) {
    struct Node* temp = head;

    // Iterate until node is NOT NULL
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addNodeDouble(struct Node** head, struct Node** tail, int data, const char* position) {
    if (position == NULL || (*position != 'h' && *position != 't')) {
        printf("Invalid position. Use 'head' or 'tail'.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        if (*position == 'h') {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        } else {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

// Function to find the nodes which have to be swapped
struct Node** find(struct Node* head, struct Node* tail) {
    struct Node* N1 = head;
    struct Node* N2 = tail;

    struct Node** result = (struct Node**)malloc(2 * sizeof(struct Node*));
    result[0] = N1;
    result[1] = N2;
    return result;
}

// Function to swap the nodes consisting of x and y
void swap(struct Node** head, struct Node** tail) {
    // Edge Cases
    if (*head == NULL || (*head)->next == NULL || (*head)->data == (*tail)->data)
        return;

    // Finding the Nodes
    struct Node** p = find(*head, *tail);
    struct Node* Node1 = p[0];
    struct Node* Node2 = p[1];

    if (Node1 == *head)
        *head = Node2;
    else if (Node2 == *head)
        *head = Node1;
    if (Node1 == *tail)
        *tail = Node2;
    else if (Node2 == *tail)
        *tail = Node1;

    // Swapping Node1 and Node2
    struct Node* temp;
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

    free(p);
}

// Driver Code
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    int val = 0;
    for (int i = 0; i < 10; i++) {
        addNodeDouble(&head, &tail, i, "tail");
        val = i;
    }

    printf("Before Swapping: ");
    print(head);

    swap(&head, &tail);

    printf("After Swapping: ");
    print(head);

    return 0;
}
