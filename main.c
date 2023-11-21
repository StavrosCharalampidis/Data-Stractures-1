#include <stdlib.h>
#include <stdio.h>

typedef struct Doubly_Linked_List
{
    int data;
    struct D_Node *next;
    struct D_Node *prev;
} S_Node;

typedef struct Singly_Linked_List
{
    int data;
    D_Node *next;
} D_Node;




// function to print the linked list
void display(D_Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    // creating 4 pointers of type D_Node
    // So these can point to address of struct type variable
    D_Node *head = NULL;
    D_Node *node2 = NULL;
    D_Node *node3 = NULL;
    D_Node *node4 = NULL;

    // allocate 3 nodes in the heap
    head = (D_Node *)malloc(sizeof(D_Node));
    node2 = (D_Node *)malloc(sizeof(D_Node));
    node3 = (D_Node *)malloc(sizeof(D_Node));
    node4 = (D_Node *)malloc(sizeof(D_Node));

    head->data = 10;    // data set for head node
    head->next = node2; // next pointer assigned to address of node2

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;

    display(head);

    return 0;
}
