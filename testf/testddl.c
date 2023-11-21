#include <stdio.h>
#include <stdlib.h>

struct node2 {
    int number;
    struct node2 *next, *prev;
};

void addNodeDouble(struct node2 **head, struct node2 **tail, int num, int thesi) {
    if (*head == NULL) {
        struct node2 * current;
        current = (struct node2 *)malloc(1 * sizeof(struct node2));
        current->number = num;
        current->prev = NULL;
        current->next = NULL;
        *head = current;
        *tail = current;
    } else {
        if (thesi == 1) {
            struct node2 *current, *temp;
            current = (struct node2 *)malloc(1 * sizeof(struct node2));
            current->number = num;
            temp = *head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = current;
            current->prev = *tail;
            current->next = NULL;
            (*tail)->next = current;
            *tail = current;
        } else  {
            struct node2 *current;
            current = (struct node2 *)malloc(1 * sizeof(struct node2));
            current->number = num;
            current->next = *head;
            (*head)->prev = current;
            *head = current;
        }
    }
}

void ReversedisplayList(struct node2 **head, struct node2 **tail) {
    struct node2 *current;
    if (*head == NULL)
        printf("I lista einai adeia!\n");
    else {
        current = *tail;
        while (current != NULL) {
            printf("%d ", current->number);
            current = current->prev;
        }
    }
}

void swapElements2(struct node2 **head, struct node2 **tail) {
    struct node2 *current, *temp;

    if (*head == NULL) {
        return;
    }

    else {
        
        temp = (*tail)->prev;
        current = *tail;
        
        
        if (*head == *tail) {
            return;
        }
        
        else {
            temp->next = *head;
            current->next = (*head)->next;
            (*head)->next = NULL;
            *head = current;
        }
       
    }
}


int main() {
    struct node2 *head, *tail;
    head = tail = NULL;

    addNodeDouble(&head, &tail, 4, 1);
    addNodeDouble(&head, &tail, 8, 1);
    addNodeDouble(&head, &tail, 3, 0);
    addNodeDouble(&head, &tail, 1, 1);
    addNodeDouble(&head, &tail, 7, 0);

    printf("\n\nDoubly linked list (reversed): ");
    ReversedisplayList(&head, &tail);
    printf("Swap: ");
    //swapElements2(&head, &tail);
    printf("\nChanged list: ");
    swapElements2(&head, &tail);
    //ReversedisplayList(&head, &tail);
    printf("\n");
}  