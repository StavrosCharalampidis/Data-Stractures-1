#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 30

typedef struct {
    char name[50];
    int customerNumber;
    int arrivalTime;
} Customer;

typedef struct {
    Customer customers[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *queue, const char *name, int customerNumber, int arrivalTime) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Η ουρά αναμονής είναι γεμάτη. Δεν μπορεί να γίνει είσοδος πελάτη.\n");
        return;
    }

    strcpy(queue->customers[queue->rear].name, name);
    queue->customers[queue->rear].customerNumber = customerNumber;
    queue->customers[queue->rear].arrivalTime = arrivalTime;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;

    printf("Επιτυχής είσοδος πελάτη στην ουρά αναμονής.\n");
}

void dequeue(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Η ουρά αναμονής είναι άδεια. Δεν υπάρχουν πελάτες για εξυπηρέτηση.\n");
        return;
    }

    printf("Ο πελάτης %d εξυπηρετήθηκε. Χρόνος αναμονής: %d λεπτά.\n",
           queue->customers[queue->front].customerNumber,
           queue->customers[queue->front].arrivalTime);

    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
}

void displayCustomers(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Η ουρά αναμονής είναι άδεια. Δεν υπάρχουν πελάτες.\n");
        return;
    }

    printf("Πελάτες προς εξυπηρέτηση:\n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("Αριθμός: %d, Όνομα: %s, Χρόνος Αναμονής: %d λεπτά\n",
               queue->customers[i].customerNumber,
               queue->customers[i].name,
               queue->customers[i].arrivalTime);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
}

int main() {
    Queue customerQueue = {{}, 0, 0};
    int customerCounter = 1;
    int choice;

    do {
        printf("\nΜΕΝΟΥ\n");
        printf("======\n");
        printf("1. Είσοδος πελάτη στην ουρά αναμονής\n");
        printf("2. Έξοδος πελάτη από την ουρά\n");
        printf("3. Εμφάνιση στοιχείων πελατών προς εξυπηρέτηση\n");
        printf("4. Πλήθος πελατών προς εξυπηρέτηση\n");
        printf("0. Έξοδος\n");
        printf("Επιλέξτε επιλογή: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                printf("Δώστε το όνομα του πελάτη: ");
                scanf("%s", name);
                int arrivalTime = rand() % 10 + 1; // Τυχαίος χρόνος αναμονής 1-10 λεπτά
                enqueue(&customerQueue, name, customerCounter++, arrivalTime);
                break;
            }
            case 2:
                dequeue(&customerQueue);
                break;
            case 3:
                displayCustomers(&customerQueue);
                break;
            case 4:
                printf("Πλήθος πελατών προς εξυπηρέτηση: %d\n", customerQueue.rear - customerQueue.front);
                break;
            case 0:
                printf("Έξοδος από το πρόγραμμα.\n");
                break;
            default:
                printf("Μη έγκυρη επιλογή. Προσπαθήστε ξανά.\n");
        }
    } while (choice != 0);

    return 0;
}