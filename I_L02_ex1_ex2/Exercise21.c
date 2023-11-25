// icsd
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


void addNodeSingle(S_Node **head, S_Node **tail, int data, const char *position);
void addDescending(S_Node **head, int value);
void displayList(S_Node *head);

int countList(S_Node *head);
void deleteNode(S_Node **head, int delVal);
void deleteFirst(S_Node **head);
S_Node *appendLists(S_Node *head1, S_Node *head2);

void addNodeDouble(D_Node **head, D_Node **tail, int data, const char *position);
void swapElements1(S_Node **head);
void swapElements2(D_Node **head, D_Node **tail);
D_Node **find(D_Node* head, D_Node *tail);
void ReversedisplayList(D_Node **head, D_Node **tail);

void freeList(D_Node *head);
void printDoublyLinkedList(D_Node *head);



int main(int argc, char const *argv[]) {
    //gcc Icsd_Lab02/Exercise21.c -o main
    //./main
    
    S_Node *singleLinkListHead1, *singleLinkListHead2, *singleLinkListTail1, *singleLinkListTail2 = NULL;

    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 6,"head");

    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 4,"head");
    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 9,"tail");
    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 2,"tail");
    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 3,"tail");
    addNodeSingle(&singleLinkListHead1, &singleLinkListTail1, 55,"tail");

    displayList(singleLinkListHead1);
    printf("Count %d singleLinkListHead1 \n", countList(singleLinkListHead1));

    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 45, "head");
    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 38, "tail");
    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 24, "tail");
    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 12, "tail");
    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 8, "tail");
    addNodeSingle(&singleLinkListHead2, &singleLinkListTail2, 61, "tail");

    addDescending(&singleLinkListHead2,3);
    displayList(singleLinkListHead2);
    printf("Count %d singleLinkListHead2 \n", countList(singleLinkListHead2));

    deleteNode(&singleLinkListHead1,55);
    deleteFirst(&singleLinkListHead1);
    displayList(singleLinkListHead1);

    printf("\n");

    S_Node *head1, *head2 = NULL;
    addDescending(&head1, 40);
    addDescending(&head1, 25);
    addDescending(&head1, 60);
    addDescending(&head1, 80);
    addDescending(&head1, 109);
    printf("singleLinkListHead1: ");
    displayList(head1);

    addDescending(&head2, 5);
    addDescending(&head2, 20);
    addDescending(&head2, 2);
    addDescending(&head2, 8);
    addDescending(&head2, 1);
    printf("singleLinkListHead2: ");
    displayList(head2);

    S_Node* result = appendLists(head1, head2);

    printf("New singleLinkList: ");
    displayList(result);

    D_Node *DoubleLinkListHead = NULL;
    D_Node *DoubleLinkListTail = NULL;

    printf("DoubleLinkListHead: ");

    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 2, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 5, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 3, "head");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 10, "tail");

    printDoublyLinkedList(DoubleLinkListHead);
    
    printf("ReversedisplayList: ");
    ReversedisplayList(&DoubleLinkListHead, &DoubleLinkListTail);
    printf("\n");

    swapElements2(&DoubleLinkListHead, &DoubleLinkListTail);
    printf("SwapElements2: ");
    printDoublyLinkedList(DoubleLinkListHead);

   
    freeList(DoubleLinkListHead);
    

    return 0;
}

int compareValues(int value1, int value2) {
    return value1 <= value2;
}

void addNodeSingle(S_Node **head, S_Node **tail, int data, const char *position) {
    if (position == NULL || (strcmp(position, "head") != 0 && strcmp(position, "tail") != 0)) {
        printf("Mh egkurh thesh 'head' h 'tail'.\n");
        return;
    }

    S_Node *newNode = (S_Node *)malloc(sizeof(S_Node));
    if (newNode == NULL) {
        printf("sfalma sthn mnimi.\n");
        return;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }
    else {
        if (strcmp(position, "head") == 0) {
            newNode->next = *head;
            *head = newNode;
        }
        else {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void addDescending(S_Node **head, int value) {
    S_Node *newNode = (S_Node *)malloc(sizeof(S_Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    newNode -> data = value;
    newNode -> next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (compareValues((*head) -> data, value)) {
        newNode -> next = *head;
        *head = newNode;
        return;
    }

    S_Node *current = *head;
    while (current -> next != NULL && compareValues(current->next->data, value)) {
        current = current->next;
    }

    newNode -> next = current->next;
    current -> next = newNode;
}


S_Node *appendLists(S_Node *head1, S_Node *head2) {
    S_Node *result = NULL;
    S_Node **lastPtrRef = &result;

    while (1) {
        if (head1 == NULL) {
            *lastPtrRef = head2;
            break;
        }
        else if (head2 == NULL) {
            *lastPtrRef = head1;
            break;
        }

        if (head1 -> data >= head2 -> data) {
            *lastPtrRef = head1;
            head1 = head1 -> next;
        }
        else {
            *lastPtrRef = head2;
            head2 = head2->next;
        }

        lastPtrRef = &((*lastPtrRef) -> next);
    }

    return result;
}


void addNodeDouble(D_Node **head, D_Node **tail, int data, const char *position) {
    if (position == NULL || (strcmp(position, "head") != 0 && strcmp(position, "tail") != 0)) {
        printf("Mh egkurh thesh 'head' h 'tail'.\n");
        return;
    }

    D_Node *newNode = (D_Node *)malloc(sizeof(D_Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
    }
    else {
        if (strcmp(position, "head") == 0) {
            newNode -> next = *head;
            (*head) -> prev = newNode;
            *head = newNode;
        }
        else {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}
void swapElements1(S_Node **head) {
    S_Node *current = *head, *temp = NULL, *index = NULL;

    if (*head == NULL) {
        return;
    }

    else {
        while (current -> next != NULL) {
            index = current;
            current = current -> next;
        }
        
        if (*head == current) {
            return;
        }
        
        else if ((*head) -> next == current) {
            temp = *head;
            *head = current;
            (*head) -> next = temp;
            temp -> next = NULL;
        }
        else {
            temp = *head; 
            *head = current;  
            (*head) -> next = temp -> next;
            index -> next = temp;
            temp -> next = NULL;
        }
    }
}


void swapElements2(D_Node **head, D_Node **tail) {
    if (*head == NULL || (*head) -> next == NULL || (*head) -> data == (*tail) -> data){
        return;
    }

    D_Node **p = find(*head, *tail);
    D_Node *Node1 = p[0];
    D_Node *Node2 = p[1];

    if (Node1 == *head) {
        *head = Node2;
    }

    else if (Node2 == *head) {
        *head = Node1;
    }

    if (Node1 == *tail) {
        *tail = Node2;
    }

    else if (Node2 == *tail) {
        *tail = Node1;
    }

    D_Node* temp;
    temp = Node1 -> next;
    Node1 -> next = Node2 -> next;
    Node2 -> next = temp;

    if (Node1 -> next != NULL) {
        Node1 -> next -> prev = Node1;
    }

    if (Node2 -> next != NULL) {
        Node2 -> next -> prev = Node2;
    }

    temp = Node1 -> prev;
    Node1 -> prev = Node2 -> prev;
    Node2 -> prev = temp;

    if (Node1 -> prev != NULL) {
        Node1 -> prev -> next = Node1;
    }

    if (Node2 -> prev != NULL) {
        Node2 -> prev -> next = Node2;
    }

    free(p);
}
D_Node **find(D_Node* head, D_Node *tail) {
    D_Node *N1 = head;
    D_Node *N2 = tail;

    D_Node **result = (D_Node **)malloc(2 * sizeof(D_Node*));
    result[0] = N1;
    result[1] = N2;
    return result;
}


void ReversedisplayList(D_Node **head, D_Node **tail) {
    if (*head == NULL){
        printf("List is Empty!\n");
    }
    else {
        while (*tail != NULL) {
            printf("%d ", (*tail) -> data);
            *tail = (*tail) -> prev;
        }
    }
}
void freeList(D_Node *head) {
    while (head != NULL) {
        D_Node *temp = head;
        head = head -> next;
        free(temp);
    }
}

void printDoublyLinkedList(D_Node *head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");

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

    if (temp != NULL && temp -> data == delVal)
    {

        *head = temp -> next;

        printf("Value %d, deleted \n", delVal);

        free(temp);
        return;
    }

    while (temp != NULL && temp -> data != delVal)
    {
        previous = temp;
        temp = temp -> next;
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
  
    *head = (*head) -> next;
    printf ("Deleted: %d\n", temp -> data);
    free (temp);
}
