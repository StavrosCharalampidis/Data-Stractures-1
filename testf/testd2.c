#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void swapElements2(struct Node** head, struct Node** tail) {
    if (*head == NULL || *tail == NULL || *head == *tail) {
        return;
    }

    
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    
    struct Node* temp = *head;
    *head = *tail;
    *tail = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void addNodeDouble(struct Node **head, struct Node **tail, int num, int thesi) {
    if (*head == NULL) {
        struct Node * current;
        current = (struct Node *)malloc(1 * sizeof(struct Node));
        current->data = num;
        current->prev = NULL;
        current->next = NULL;
        *head = current;
        *tail = current;
    } else {
        if (thesi == 1) {
            struct Node *current, *temp;
            current = (struct Node *)malloc(1 * sizeof(struct Node));
            current->data = num;
            temp = *head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = current;
            current->prev = *tail;
            current->next = NULL;
            (*tail)->next = current;
            *tail = current;
        } else  {
            struct Node *current;
            current = (struct Node *)malloc(1 * sizeof(struct Node));
            current->data = num;
            current->next = *head;
            (*head)->prev = current;
            *head = current;
        }
    }
}

int main() {
    
    struct Node *head, *tail = NULL;

    addNodeDouble(&head, &tail, 4, 1);
    addNodeDouble(&head, &tail, 8, 1);
    addNodeDouble(&head, &tail, 3, 0);
    addNodeDouble(&head, &tail, 1, 1);
    addNodeDouble(&head, &tail, 7, 0);
    printList(head);

    swapElements2(&head, &tail);
    printf("Λίστα μετά την αντιστροφή: ");
    printList(head);

    
    return 0;
}
