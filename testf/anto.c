//icsd
#include <stdlib.h>
#include <stdio.h>


typedef struct Doubly_Linked_List
{
    int data;
    struct Doubly_Linked_List *next;
    struct Doubly_Linked_List *prev;
} D_Node;

void addNodeSingle(D_Node **head, int data, const char *position)
{
    if (position == NULL || (*position != 'h' && *position != 't'))
    {
        printf("Μη έγκυρη θέση. Χρησιμοποιήστε 'head' ή 'tail'.\n");
        return;
    }

    D_Node *newNode = (D_Node *)malloc(sizeof(D_Node));
    if (newNode == NULL)
    {
        printf("Σφάλμα στην ανάθεση μνήμης για τον νέο κόμβο.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        D_Node *current = *head;

        if (*position == 'h')
        {
            newNode->next = *head;
            *head = newNode;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}


void freeList(D_Node *head)
{
    while (head != NULL)
    {
        D_Node *temp = head;
        head = head->next;
        free(temp);
    }
}


void printList(D_Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    struct Node *singleLinkListHead = NULL;

    printf("Αρχική λίστα: ");

    addNodeSingle(&singleLinkListHead, 2, "tail");
    addNodeSingle(&singleLinkListHead, 5, "tail");
    addNodeSingle(&singleLinkListHead, 3, "head");
    addNodeSingle(&singleLinkListHead, 10, "tail");

    printList(singleLinkListHead);

    // Απελευθέρωση της μνήμης που καταλαμβάνει η λίστα
    freeList(singleLinkListHead);
    return 0;
}
