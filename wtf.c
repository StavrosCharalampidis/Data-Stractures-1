#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

void swapElements2(Node** head, Node** tail) {
    if (*head == NULL || *tail == NULL) {
        return;
    }
    
    Node* firstNode = *head;
    Node* lastNode = *tail;
    
    Node* temp = firstNode->next;
    firstNode->next = lastNode->next;
    lastNode->next = temp;
    
    if (firstNode->next != NULL) {
        firstNode->next->prev = firstNode;
    }
    if (lastNode->next != NULL) {
        lastNode->next->prev = lastNode;
    }
    
    *head = lastNode;
    *tail = firstNode;
}

void printList(Node* node) {
    Node *end;
    printf ("List in Forward direction: ");

    while (node != NULL)
    {
        printf (" %d ", node->data);
        end = node;
        node = node->next;
    }

    printf ("\nList in backward direction: ");

    while (end != NULL)
    {
        printf (" %d ", end->data);
        end = end->prev;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    // Δημιουργία της διπλά διασυνδεδεμένης λίστας
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    
    node1->data = 1;
    node1->prev = NULL;
    node1->next = node2;
    
    node2->data = 2;
    node2->prev = node1;
    node2->next = node3;
    
    node3->data = 3;
    node3->prev = node2;
    node3->next = NULL;
    
    head = node1;
    tail = node3;
    
    printf("Original list: \n");
    printList(head);
    
    //swapElements2(&head, &tail);
    
    printf("\nSwapped list: \n");
    printList(head);
    
    printf("\n");
    return 0;
}
