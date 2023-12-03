
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Ylopoihsh Singly Linked List
typedef struct Singly_Linked_List
{
    int data;
    struct Singly_Linked_List *next;
} S_Node;

//Ylopoihsh Doubly Linked List
typedef struct Doubly_Linked_List
{
    int data;
    struct Doubly_Linked_List *next;
    struct Doubly_Linked_List *prev;
} D_Node;

// ypografes sinartiseon 
void addNodeSingle(S_Node **head, int data, const char *position);
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
void printList(D_Node *head);



int main() {
    //orismos singleLinkListHeadSwap
    S_Node *singleLinkListHeadSwap = NULL;
    //prosthiki se kombo me basi to head h tail
    addNodeSingle(&singleLinkListHeadSwap, 49, "head");
    addNodeSingle(&singleLinkListHeadSwap,3, "tail");
    addNodeSingle(&singleLinkListHeadSwap,23, "head");
    addNodeSingle(&singleLinkListHeadSwap,9, "tail");
    addNodeSingle(&singleLinkListHeadSwap,12, "tail");
    addNodeSingle(&singleLinkListHeadSwap, 6, "head");
    //before swapElements
    
    printf("before swap: ");
    displayList(singleLinkListHeadSwap);
    //alagi tou head sto telos kai to teleuteo sto proto
    printf("SwapElements1: ");
    swapElements1(&singleLinkListHeadSwap);
    displayList(singleLinkListHeadSwap);

    printf("\n");
    //orismos singleLinkListHeads
    S_Node *singleLinkListHead1, *singleLinkListHead2 = NULL;

    //prosthiki se kombo me basi to head h tail
    addNodeSingle(&singleLinkListHead1, 6,"tail");
    addNodeSingle(&singleLinkListHead1, 4,"head");
    addNodeSingle(&singleLinkListHead1, 9,"tail");
    addNodeSingle(&singleLinkListHead1, 2,"tail");
    addNodeSingle(&singleLinkListHead1, 3,"tail");
    addNodeSingle(&singleLinkListHead1, 55,"tail");

    //ektiposi tis singleLinkListHead1
    printf("singleLinkListHead1: ");
    displayList(singleLinkListHead1);
    printf("Count %d singleLinkListHead1 \n", countList(singleLinkListHead1));

    //prosthiki se kombo me basi to head h tail
    addNodeSingle(&singleLinkListHead2, 45, "head");
    addNodeSingle(&singleLinkListHead2,38, "tail");
    addNodeSingle(&singleLinkListHead2,24, "tail");
    addNodeSingle(&singleLinkListHead2,12, "tail");
    addNodeSingle(&singleLinkListHead2,8, "tail");
    addNodeSingle(&singleLinkListHead2, 61, "tail");

    //ektiposi tis singleLinkListHead2
    printf("singleLinkListHead2: ");
    displayList(singleLinkListHead2);

    //ektiposi tou countList 
    printf("Count %d singleLinkListHead2 \n", countList(singleLinkListHead2));

    //diagrafi kombou
    deleteNode(&singleLinkListHead1,55);

    //diagrafi protou kombou
    deleteFirst(&singleLinkListHead1);

    //ektiposi tis singleLinkListHead1
    printf("singleLinkListHead1: ");
    displayList(singleLinkListHead1);

    printf("\n");


    //orismos Heads
    S_Node *head1, *head2 = NULL;

    //prosthiki se kombo me fthinousa sira
    addDescending(&head1, 40);
    addDescending(&head1, 25);
    addDescending(&head1, 60);
    addDescending(&head1, 80);
    addDescending(&head1, 109);

    //ektiposi tis head1
    printf("singleLinkListHead1: ");
    displayList(head1);

    //prosthiki se kombo me fthinousa sira
    addDescending(&head2, 5);
    addDescending(&head2, 20);
    addDescending(&head2, 2);
    addDescending(&head2, 8);
    addDescending(&head2, 1);

    //ektiposi tis head2
    printf("singleLinkListHead2: ");
    displayList(head2);

    //enosi dion single linked list 
    S_Node* result = appendLists(head1, head2);

    //ektiposi tis enosis
    printf("New singleLinkList: ");
    displayList(result);

    //orismos DoubleLinkListHead kai DoubleLinkListTail
    D_Node *DoubleLinkListHead, *DoubleLinkListTail = NULL;

    //prosthiki se kombo me basi to head h tail
    printf("DoubleLinkListHead: ");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 2, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 5, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 3, "head");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 10, "tail");

    //ektiposi tis listas
    printList(DoubleLinkListHead);
    
    //ektiposi tis listas anapoda
    printf("ReversedisplayList: ");
    ReversedisplayList(&DoubleLinkListHead, &DoubleLinkListTail);
    printf("\n");


    //allazi to head me to tail diladi o protos komvos paei sto telos kai o teleutos ston proto
    swapElements2(&DoubleLinkListHead, &DoubleLinkListTail);
    printf("SwapElements2: ");
    printList(DoubleLinkListHead);

   
    freeList(DoubleLinkListHead);
    

    return 0;
}


void addNodeSingle(S_Node **head, int data, const char *position) {
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
    }

    else {
        S_Node *current = *head;

        if (strcmp(position, "head") == 0) {
            newNode->next = *head;
            *head = newNode;
        }
        else {
            while (current -> next != NULL) {
                current = current -> next;
            }
            current -> next = newNode;
        }
    }
}

void addDescending(S_Node **head, int value) {
    S_Node *newNode = (S_Node *)malloc(sizeof(S_Node));
    newNode -> data = value;
    newNode -> next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if ((*head) -> data <= value) {
        newNode -> next = *head;
        *head = newNode;
        return;
    }

    S_Node *current = *head;
    while (current -> next != NULL && current->next->data > value) {
        current = current->next;
    }

    newNode -> next = current->next;
    current -> next = newNode;
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
    D_Node *current;
    if (*head == NULL){
        printf("List is Empty!\n");
    }
    else {
        current = *tail;
        while (current != NULL) {
            printf("%d ", current -> data);
            current = current -> prev;
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

void printList(D_Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
