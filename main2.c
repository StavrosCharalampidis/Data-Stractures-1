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
void addDescending(S_Node **head, int value);
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
    S_Node *SingleLinkList1, *SingleLinkList2 = NULL;
    D_Node *DoubleLinkList1, *DoubleLinkList2 = NULL;

    createNode(&SingleLinkList1,6);
    createNode(&SingleLinkList1,4);
    createNode(&SingleLinkList1,9);
    createNode(&SingleLinkList1,2);
    createNode(&SingleLinkList1,3);

    addNodeSingle(&SingleLinkList1, 55,"head");

    displayList(SingleLinkList1);
    printf("%d count SingleLinkList1 \n", countList(SingleLinkList1));

    createNode(&SingleLinkList2,45);
    createNode(&SingleLinkList2,38);
    createNode(&SingleLinkList2,24);
    createNode(&SingleLinkList2,12);
    createNode(&SingleLinkList2,8);


    addNodeSingle(&SingleLinkList2, 61, "tail");
    addDescending(&SingleLinkList2,3);
    displayList(SingleLinkList2);
    printf("%d count SingleLinkList2 \n", countList(SingleLinkList2));

    deleteNode(&SingleLinkList1,55);
    deleteFirst(&SingleLinkList1);
    displayList(SingleLinkList1);

    printf("\n");

    S_Node *head1, *head2 = NULL;
    addDescending(&head1, 40);
    addDescending(&head1, 25);
    addDescending(&head1, 60);
    addDescending(&head1, 80);
    addDescending(&head1, 109);
    printf("SingleLinkList1: ");
    displayList(head1);

    addDescending(&head2, 5);
    addDescending(&head2, 20);
    addDescending(&head2, 2);
    addDescending(&head2, 8);
    addDescending(&head2, 1);
    printf("SingleLinkList2: ");
    displayList(head2);

    S_Node* result = appendLists(head1, head2);

    printf("New SLL: ");
    displayList(result);
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


void addDescending(S_Node **head, int value) {
    S_Node *newNode = (S_Node *)malloc(sizeof(S_Node));
    newNode->data = value;
    newNode->next = NULL;

    

        if (*head == NULL)
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

    S_Node *current = *head;
    while (current->next != NULL && current->next->data > value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
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