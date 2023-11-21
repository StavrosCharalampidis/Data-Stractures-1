#include <stdio.h>
#include <stdlib.h>

// Δομή για έναν κόμβο της λίστας
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Συνάρτηση για την προσθήκη νέου κόμβου σε καθορισμένη θέση της λίστας
void addNodeDouble(struct Node **head, struct Node **tail, int data, const char *position) {
    if (position == NULL || (*position != 'h' && *position != 't'))
    {
        printf("Μη έγκυρη θέση. Χρησιμοποιήστε 'head' ή 'tail'.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        if (*position == 'h')
        {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
        else
        {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
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
    struct Node *DoubleLinkListHead = NULL;
    struct Node *DoubleLinkListTail = NULL;

    printf("Αρχική λίστα: ");

    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 2, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 5, "tail");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 3, "head");
    addNodeDouble(&DoubleLinkListHead, &DoubleLinkListTail, 10, "tail");

    printList(DoubleLinkListHead);

    // Απελευθέρωση της μνήμης που καταλαμβάνει η λίστα
    freeList(DoubleLinkListHead);

    return 0;
}
