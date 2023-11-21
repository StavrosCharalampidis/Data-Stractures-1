#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addDescending(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    

        if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    if ((*head)->data <= newData)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && current->next->data > newData)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head1 = NULL;

    addDescending(&head1, 5);
    addDescending(&head1, 20);
    addDescending(&head1, 2);
    addDescending(&head1, 8);
    addDescending(&head1, 1);

    printf("Sorted list: ");
    printList(head1);

    return 0;
}