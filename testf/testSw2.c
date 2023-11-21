#include <stdio.h>
#include <stdlib.h>

// Δομή για έναν κόμβο της λίστας
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Συνάρτηση για τη δημιουργία ενός νέου κόμβου
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Σφάλμα στην ανάθεση μνήμης για τον νέο κόμβο.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


// Συνάρτηση για την αντιστροφή του πρώτου και του τελευταίου κόμβου
void swapElements22(struct Node **head, struct Node **tail)
{
    if (*head == NULL || *tail == NULL || *head == *tail)
    {
        // Η λίστα είναι ήδη άδεια ή έχει μόνο ένα στοιχείο, δεν χρειάζεται αντιστροφή
        return;
    }

    struct Node *firstNode = *head;
    struct Node *lastNode = *tail;

    // Αντιμετάθεση των δεικτών next και prev
    firstNode->next = lastNode->next;
    lastNode->prev = firstNode->prev;

    if (firstNode->next != NULL)
    {
        firstNode->next->prev = firstNode;
    }

    if (lastNode->prev != NULL)
    {
        lastNode->prev->next = lastNode;
    }

    // Αντιμετάθεση των δεικτών του πρώτου κόμβου
    firstNode->prev = lastNode;
    firstNode->next = NULL;

    // Αντιμετάθεση των δεικτών του τελευταίου κόμβου
    lastNode->next = firstNode;
    lastNode->prev = NULL;

    // Ανάθεση του πρώτου κόμβου στο τέλος και του τελευταίου στην αρχή
    *head = lastNode;
    *tail = firstNode;
}

// Συνάρτηση για την αντιστροφή του πρώτου και του τελευταίου κόμβου
void swapElements222(struct Node **head, struct Node **tail)
{
    if (*head == NULL || *tail == NULL || *head == *tail)
    {
        // Η λίστα είναι ήδη άδεια ή έχει μόνο ένα στοιχείο, δεν χρειάζεται αντιστροφή
        return;
    }

    struct Node *firstNode = *head;
    struct Node *lastNode = *tail;

    // Αντιστροφή μόνο αν οι δείκτες δεν είναι ήδη ίδιοι
    if (firstNode->next != lastNode && lastNode->prev != firstNode)
    {
        // Αντιμετάθεση των δεικτών next και prev
        firstNode->next = lastNode->next;
        lastNode->prev = firstNode->prev;

        if (firstNode->next != NULL)
        {
            firstNode->next->prev = firstNode;
        }

        if (lastNode->prev != NULL)
        {
            lastNode->prev->next = lastNode;
        }

        // Αντιμετάθεση των δεικτών του πρώτου κόμβου
        firstNode->prev = lastNode;
        firstNode->next = NULL;

        // Αντιμετάθεση των δεικτών του τελευταίου κόμβου
        lastNode->next = firstNode;
        lastNode->prev = NULL;

        // Ανάθεση του πρώτου κόμβου στο τέλος και του τελευταίου στην αρχή
        *head = lastNode;
        *tail = firstNode;
    }
}


// Συνάρτηση για την αντιστροφή του πρώτου και του τελευταίου κόμβου
void swapElements2(struct Node **head, struct Node **tail)
{
    if (*head == NULL || *tail == NULL || *head == *tail)
    {
        // Η λίστα είναι ήδη άδεια ή έχει μόνο ένα στοιχείο, δεν χρειάζεται αντιστροφή
        return;
    }

    struct Node *firstNode = *head;
    struct Node *lastNode = *tail;

    // Αντιμετάθεση των δεικτών του πρώτου κόμβου
    struct Node *temp = firstNode->next;
    firstNode->next = lastNode->next;
    lastNode->next = temp;

    if (firstNode->next != NULL)
    {
        firstNode->next->prev = firstNode;
    }

    // Αντιμετάθεση των δεικτών του τελευταίου κόμβου
    temp = lastNode->prev;
    lastNode->prev = firstNode->prev;
    firstNode->prev = temp;

    if (lastNode->prev != NULL)
    {
        lastNode->prev->next = lastNode;
    }

    // Ανάθεση του πρώτου κόμβου στο τέλος και του τελευταίου στην αρχή
    *head = lastNode;
    *tail = firstNode;
}




// Συνάρτηση για την αντιστροφή του πρώτου και του τελευταίου κόμβου
void swapElements2(struct Node **head, struct Node **tail)
{
    if (*head == NULL || *tail == NULL || *head == *tail || (*head)->next == *tail)
    {
        // Η λίστα είναι ήδη άδεια, έχει μόνο έναν κόμβο ή οι πρώτος και τελευταίος κόμβος είναι δίπλα-δίπλα
        return;
    }

    struct Node *firstNode = *head;
    struct Node *lastNode = *tail;

    // Αντιμετάθεση των δεικτών του πρώτου κόμβου
    struct Node *temp = firstNode->next;
    firstNode->next = lastNode->next;
    lastNode->next = temp;

    if (firstNode->next != NULL)
    {
        firstNode->next->prev = firstNode;
    }

    // Αντιμετάθεση των δεικτών του τελευταίου κόμβου
    temp = lastNode->prev;
    lastNode->prev = firstNode->prev;
    firstNode->prev = temp;

    if (lastNode->prev != NULL)
    {
        lastNode->prev->next = lastNode;
    }

    // Ανάθεση του πρώτου κόμβου στο τέλος και του τελευταίου στην αρχή
    *head = lastNode;
    *tail = firstNode;
}

// Συνάρτηση για την εκτύπωση της λίστας
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Συνάρτηση για την απελευθέρωση της μνήμης που καταλαμβάνει η λίστα
void freeList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *doubleLinkListHead = NULL;
    struct Node *doubleLinkListTail = NULL;

    // Προσθήκη κόμβων στη διπλά διασυνδεδεμένη λίστα
    for (int i = 1; i <= 5; ++i)
    {
        struct Node *newNode = createNode(i);
        if (doubleLinkListHead == NULL)
        {
            doubleLinkListHead = doubleLinkListTail = newNode;
        }
        else
        {
            newNode->prev = doubleLinkListTail;
            doubleLinkListTail->next = newNode;
            doubleLinkListTail = newNode;
        }
    }

    printf("Αρχική λίστα: ");
    printList(doubleLinkListHead);

    // Κλήση της συνάρτησης για αντιστροφή του πρώτου και του τελευταίου κόμβου
    swapElements2(&doubleLinkListHead, &doubleLinkListTail);

    printf("Λίστα μετά την αντιστροφή: ");
    printList(doubleLinkListHead);

    // Απελευθέρωση της μνήμης που καταλαμβάνει η λίστα
    freeList(doubleLinkListHead);

    return 0;
}
