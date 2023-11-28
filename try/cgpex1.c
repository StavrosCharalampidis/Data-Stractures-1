#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ορισμός του κόμβου για την απλή συνδεδεμένη λίστα
struct NodeSingle {
    int data;
    struct NodeSingle* next;
};

// Ορισμός του κόμβου για τη διπλή συνδεδεμένη λίστα
struct NodeDouble {
    int data;
    struct NodeDouble* next;
    struct NodeDouble* prev;
};

// Συνάρτηση προσθήκης κόμβου σε απλή συνδεδεμένη λίστα
void addNodeSingle(struct NodeSingle** head, int data, const char* position) {
    struct NodeSingle* newNode = (struct NodeSingle*)malloc(sizeof(struct NodeSingle));
    newNode->data = data;
    newNode->next = NULL;

    if (strcmp(position, "head") == 0) {
        newNode->next = *head;
        *head = newNode;
    } else if (strcmp(position, "tail") == 0) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct NodeSingle* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    } else {
        printf("Invalid position. Use 'head' or 'tail'.\n");
        free(newNode);
    }
}

// Συνάρτηση προσθήκης κόμβου σε διπλή συνδεδεμένη λίστα
void addNodeDouble(struct NodeDouble** head, struct NodeDouble** tail, int data, const char* position) {
    struct NodeDouble* newNode = (struct NodeDouble*)malloc(sizeof(struct NodeDouble));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (strcmp(position, "head") == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        } else {
            *tail = newNode; // Αν η λίστα ήταν άδεια, το tail είναι το ίδιο με το head
        }
        *head = newNode;
    } else if (strcmp(position, "tail") == 0) {
        newNode->prev = *tail;
        if (*tail != NULL) {
            (*tail)->next = newNode;
        } else {
            *head = newNode; // Αν η λίστα ήταν άδεια, το head είναι το ίδιο με το tail
        }
        *tail = newNode;
    } else {
        printf("Invalid position. Use 'head' or 'tail'.\n");
        free(newNode);
    }
}

// Συνάρτηση προσθήκης κόμβου σε ταξινομημένη κατά φθίνουσα σειρά λίστα
void addDescending(struct NodeSingle** head, int data) {
    struct NodeSingle* newNode = (struct NodeSingle*)malloc(sizeof(struct NodeSingle));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || data > (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct NodeSingle* temp = *head;
        while (temp->next != NULL && temp->next->data > data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Συνάρτηση εμφάνισης απλής συνδεδεμένης λίστας
void displayList(struct NodeSingle* head) {
    struct NodeSingle* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Συνάρτηση εμφάνισης ανάποδης απλής συνδεδεμένης λίστας
void ReversedisplayList(struct NodeSingle* head) {
    if (head == NULL) {
        return;
    }
    
    ReversedisplayList(head->next);
    printf("%d -> ", head->data);
}

// Συνάρτηση πλήθους στοιχείων απλής συνδεδεμένης λίστας
int countList(struct NodeSingle* head) {
    int count = 0;
    struct NodeSingle* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Συνάρτηση διαγραφής κόμβου απλής συνδεδεμένης λίστας
void deleteNode(struct NodeSingle** head, int data) {
    struct NodeSingle* current = *head;
    struct NodeSingle* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Συνάρτηση διαγραφής πρώτου κόμβου απλής συνδεδεμένης λίστας
void deleteFirst(struct NodeSingle** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct NodeSingle* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Συνάρτηση ενώσης δύο ταξινομημένων απλών συνδεδεμένων λιστών
struct NodeSingle* appendLists(struct NodeSingle* head1, struct NodeSingle* head2) {
    struct NodeSingle* result = NULL;
    struct NodeSingle* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data >= head2->data) {
            addNodeSingle(&result, head1->data, "tail");
            head1 = head1->next;
        } else {
            addNodeSingle(&result, head2->data, "tail");
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        addNodeSingle(&result, head1->data, "tail");
        head1 = head1->next;
    }

    while (head2 != NULL) {
        addNodeSingle(&result, head2->data, "tail");
        head2 = head2->next;
    }

    return result;
}

// Συνάρτηση αντιστροφής του πρώτου με του τελευταίου στοιχείου απλής συνδεδεμένης λίστας

void swapElements1(struct NodeSingle **head) {
    struct NodeSingle *current = *head, *temp = NULL, *index = NULL;

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

// Συνάρτηση αντιστροφής του πρώτου με του τελευταίου στοιχείου διπλής συνδεδεμένης λίστας
void swapElements2(struct NodeDouble** head, struct NodeDouble** tail) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List has less than two elements. Cannot swap.\n");
        return;
    }

    struct NodeDouble* first = *head;
    struct NodeDouble* last = *tail;
    struct NodeDouble* secondLast = last->prev;

    *head = last;
    last->prev = NULL;
    last->next = first->next;
    first->next->prev = last;
    secondLast->next = first;
    first->next = NULL;
    first->prev = secondLast;
}

int main() {
    struct NodeSingle* list1 = NULL;
    struct NodeSingle* list2 = NULL;

    // Προσθήκη στοιχείων σε απλή συνδεδεμένη λίστα
    addNodeSingle(&list1, 10, "tail");
    addNodeSingle(&list1, 20, "tail");
    addNodeSingle(&list1, 30, "tail");
    printf("List 1: ");
    displayList(list1);

    // Προσθήκη στοιχείων σε διπλή συνδεδεμένη λίστα
    struct NodeDouble* dlist1Head = NULL;
    struct NodeDouble* dlist1Tail = NULL;
    addNodeDouble(&dlist1Head, &dlist1Tail, 10, "tail");
    addNodeDouble(&dlist1Head, &dlist1Tail, 20, "tail");
    addNodeDouble(&dlist1Head, &dlist1Tail, 30, "tail");
    printf("\nDouble List 1: ");
    // Displaying doubly linked list forwards
    struct NodeDouble* dcurrent = dlist1Head;
    while (dcurrent != NULL) {
        printf("%d -> ", dcurrent->data);
        dcurrent = dcurrent->next;
    }
    printf("NULL\n");

    // Προσθήκη στοιχείων σε ταξινομημένη απλή συνδεδεμένη λίστα
    addDescending(&list2, 25);
    addDescending(&list2, 15);
    addDescending(&list2, 5);
    printf("\nList 2 (sorted): ");
    displayList(list2);

    // Διαγραφή πρώτου στοιχείου
    //deleteFirst(&list1);
    printf("\nAfter deleting the first element from List 1: ");
    displayList(list1);

    // Αντιστροφή πρώτου με τελευταίου στοιχείου
    swapElements1(&list1);
    printf("\nAfter swapping first and last elements of List 1: ");
    displayList(list1);

    // Ενώνουμε τις δύο ταξινομημένες λίστες σε μία νέα λίστα
    struct NodeSingle* mergedList = appendLists(list1, list2);
    printf("\nMerged Sorted List: ");
    displayList(mergedList);

    // Αντιστροφή πρώτου με τελευταίου στοιχείου διπλής συνδεδεμένης λίστας
    swapElements2(&dlist1Head, &dlist1Tail);
    printf("\nAfter swapping first and last elements of Double List 1: ");
    // Displaying doubly linked list backwards
    struct NodeDouble* dcurrentBackwards = dlist1Tail;
    while (dcurrentBackwards != NULL) {
        printf("%d -> ", dcurrentBackwards->data);
        dcurrentBackwards = dcurrentBackwards->prev;
    }
    printf("NULL\n");

    
}