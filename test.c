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


void addNodeSingle(S_Node **head, int value, char * pos);
void addAscending(S_Node **head, int value);
void displayList(S_Node *head);
int countList(S_Node *head);
void deleteNode(S_Node **head, int delVal);
void deleteFirst(S_Node **head);
S_Node *appendLists(S_Node *head1, S_Node *head2);



void createNode(S_Node **head, int value)
{
    S_Node *newNode;
    newNode = (S_Node *) malloc(sizeof(S_Node));
    newNode->data=value;
    if(*head==NULL)
    {
        newNode->next=NULL;
        *head=newNode;
    }
    else
    {
        newNode->next=*head;
        *head=newNode;
    }
}


int main(int argc, char const *argv[])
{
    S_Node *lista;
    S_Node *l1;
    lista=NULL;
    l1=NULL;

    D_Node *lista2, *lista2last;
    lista2=NULL;
    lista2last=NULL;

    createNode(&lista,6);
    createNode(&lista,4);
    createNode(&lista,9);
    createNode(&lista,2);
    createNode(&lista,3);

    addNodeSingle(&lista, 55,"head");

    displayList(lista);
    printf("%d count lista \n", countList(lista));

    createNode(&l1,45);
    createNode(&l1,38);
    createNode(&l1,24);
    createNode(&l1,12);
    createNode(&l1,8);


    addNodeSingle(&l1, 61, "tail");
    addAscending(&l1,3);
    displayList(l1);
    printf("%d count li \n", countList(l1));

    deleteNode(&lista,55);
    deleteFirst(&lista);
    displayList(lista);

   
    displayList(l1);


    return 0;
}

void addNodeSingle(S_Node **head, int value, char * pos) {
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

S_Node *appendLists(S_Node *head1, S_Node *head2)
{
    S_Node *result = NULL;
    S_Node **lastPtrRef = &result;
    while (1)
    {
        if (head1 == NULL)
        {
            *lastPtrRef = head2;
            break;
        }
        else if (head2 == NULL)
        {
            *lastPtrRef = head1;
            break;
        }

        if (head1->data >= head2->data)
        {
            *lastPtrRef = head1;
            head1 = head1->next;
        }
        else
        {
            *lastPtrRef = head2;
            head2 = head2->next;
        }

        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}