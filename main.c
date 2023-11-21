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


void addNodeSingle(S_Node **head, int value, char pos);
void addDescending(S_Node **head, int value);
void displayList(S_Node *head);
int countList(S_Node *head);
void deleteNode(S_Node **head, int delVal);
void deleteFirst(S_Node **head);

void appendLists(){}
void addNodeDouble(){}
void swapElements1(){}
void swapElements2(){}
void ReversedisplayList(){}



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

void addNodeSingle(S_Node **head, int value, char pos) {
    S_Node *newNode;
    newNode = (S_Node *) malloc (sizeof(S_Node));
    newNode -> data = value;

    if(pos == "head") {
        newNode -> next= *head;
        *head = newNode;
    }

    else if(pos == "tail") {
        S_Node *p;
        p = *head;

        while(p -> next != NULL) {
            p = p -> next;
        }

        newNode -> next = p -> next;
        p -> next = newNode;

    }
}

void addAscending(S_Node **head, int value) {
    S_Node *newNode,*temp = *head, *p;
    newNode = (S_Node *) malloc (sizeof(S_Node));
    newNode -> data = value;

    while (newNode -> data > temp -> data) {
        p = temp;
        temp = temp -> next;
        if (temp -> next == NULL) {
            break;
        }
    }

    if (*head == NULL) {
        newNode -> next = NULL;
        *head = newNode;
    }

    else if (newNode -> data < temp -> data) {
        newNode -> next = *head;
        *head = newNode;
    }

    else if (newNode -> data > temp -> data) { 
        newNode -> next = NULL;
        temp -> next = newNode;
    }

    else {
        temp = newNode;
        newNode -> next = p -> next;
        p -> next = temp;
    }
}

void displayList(S_Node *head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
    
}

int countList(S_Node *head) {
    int i = 0;

    while (head != NULL) {
        head = head -> next;
        i++;
    }

    return i;
}

void deleteNode(S_Node **head, int delVal) {
    S_Node *temp = *head;
    S_Node *previous;

    if (*head == NULL)
    {
        printf("The list is empty \n");
        return;
    }

    if (temp -> next == NULL)
    {
        *head = NULL;
        free(temp);
        printf("Value %d, deleted \n", delVal);
        return;
    }

    if (temp != NULL && temp->data == delVal)
    {

        *head = temp->next;

        printf("Value %d, deleted \n", delVal);

        free(temp);
        return;
    }

    while (temp != NULL && temp->data != delVal)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    previous -> next = temp -> next;
    free(temp);

    printf("Value %d, deleted \n", delVal);
}

void deleteFirst(S_Node **head) {
    S_Node *temp = *head;

    if (*head == NULL) {
        printf ("Linked List Empty, nothing to delete");
        return;
    }
  
    *head = (*head)->next;
    printf ("Deleted: %d\n", temp->data);
    free (temp);
}
