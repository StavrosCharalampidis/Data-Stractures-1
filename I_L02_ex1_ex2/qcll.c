#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 30

typedef struct Circular_Linked_List {
    char *name[QUEUE_SIZE];
    int clientNumber;
    int entranceTime;
    struct Circular_Linked_List *next;
} C_Node;


void deleteBegin(C_Node **head) {

    C_Node *tempNode = *head;

    // if there are no nodes in Linked List can't delete
    if (*head == NULL)
    {
        printf("Linked List Empty, nothing to delete");
        return;
    }

    // if only 1 node in CLL
    if (tempNode->next == *head)
    {
        *head = NULL;
        return;
    }

    C_Node *curr = *head;

    // traverse till last node in CLL
    while (curr->next != *head)
        curr = curr->next;

    // assign last node's next to 2nd node in CLL
    curr->next = (*head)->next;

    // move head to next node
    *head = (*head)->next;
    free(tempNode);
}

void display(C_Node *head)
{
    // if there are no node in CLL
    if (head == NULL)
        return;

    C_Node *temp = head;

    // need to take care of circular structure of CLL
    do
    {
        printf("%s ", temp->name);
        temp = temp->next;

    } while (temp != head);
    printf("\n");
}

void insertLast(C_Node **head, char *data[])
{
    C_Node *newNode = (C_Node *)malloc(sizeof(C_Node));
    *newNode->name = data;

    // if its the first node being entered
    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        return;
    }

    // if LL already as >=1 node
    C_Node *curr = *head;

    // traverse till last node in LL
    while (curr->next != *head)
    {
        curr = curr->next;
    }

    // assign LL's current last node's next as this new node
    curr->next = newNode;

    // assign this new node's next as current head of LL
    newNode->next = *head;
}

int main()
{

    C_Node *head = NULL;

    printf("Linked List: ");
    insertLast(&head, "wAA");
    insertLast(&head, "ww");

    deleteBegin(&head);
    display(head);

    return 0;
}