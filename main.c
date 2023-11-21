#include <stdlib.h>
#include <stdio.h>


typedef struct Singly_Linked_List
{
    int data;
    struct Singly_Linked_List *next;
} S_Node;


typedef struct Doubly_Linked_List
{
    int data;
    struct Doubly_Linked_List *next;
    struct Doubly_Linked_List *prev;
} D_Node;


void addNodeSingle(){}
void addDescending(){}
void displayList(){}
void countList(){}
void deleteNode(){}
void deleteFirst(){}

void appendLists(){}
void addNodeDouble(){}
void swapElements1(){}
void swapElements2(){}
void ReversedisplayList(){}


// function to print the linked list
void display(S_Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    S_Node *head = NULL;
    S_Node *node2 = NULL;
    S_Node *node3 = NULL;
    S_Node *node4 = NULL;

    // allocate 3 nodes in the heap
    head = (S_Node *)malloc(sizeof(S_Node));
    node2 = (S_Node *)malloc(sizeof(S_Node));
    node3 = (S_Node *)malloc(sizeof(S_Node));
    node4 = (S_Node *)malloc(sizeof(S_Node));

    head->data = 10;
    head->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;

    display(head);

    return 0;
}
