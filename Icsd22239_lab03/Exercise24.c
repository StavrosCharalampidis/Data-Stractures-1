
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 30

//Ylopoihsh Customer
typedef struct Customer {
    char name[MAX_QUEUE_SIZE];
    int customerNumber;
    int arrivalTime;
} Customer;

//Ylopoihsh Queue
typedef struct Queue{
    Customer customers[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// ypografes sinartiseon 
void enqueue(Queue *queue, const char *name, int customerNumber, int arrivalTime);
void dequeue(Queue *queue);
void displayCustomers(Queue *queue);

int main() {
    Queue customerQueue = {{}, 0, 0};
    int customerCounter = 1;
    int choice;

    do
    {
        printf("\nMENU\n");
        printf("=====\n");
        printf("1. Enter customer into the queue.\n");
        printf("2. Exit customer from the queue.\n");
        printf("3. Display customer details in the queue.\n");
        printf("4. Number of customers in the queue.\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char name[50];
            printf("Enter customer name:");
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
            printf("Number of customers in the queue: %d\n", customerQueue.rear - customerQueue.front);
            break;
        case 0:
            printf("Exit.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}

void enqueue(Queue *queue, const char *name, int customerNumber, int arrivalTime)
{
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front)
    {
        printf("Queue is full. Cannot add customer\n");
        return;
    }

    strcpy(queue->customers[queue->rear].name, name);
    queue->customers[queue->rear].customerNumber = customerNumber;
    queue->customers[queue->rear].arrivalTime = arrivalTime;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;

    printf("Customer %s entered the queue.\n", queue->customers[queue->rear].name);
}

void dequeue(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("Queue is empty. No customer to remove.\n");
        return;
    }

    printf("Customer %s with customerNumber %d exited the queue. %d minutes.\n",
           queue->customers[queue->front].name,
           queue->customers[queue->front].customerNumber,
           queue->customers[queue->front].arrivalTime);

    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
}

void displayCustomers(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("Queue is empty. No customer to remove.\n");
        return;
    }

    printf("Customers to serve:\n");
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("Number: %d, Name: %s, EntranceTime: %d minutes\n",
               queue->customers[i].customerNumber,
               queue->customers[i].name,
               queue->customers[i].arrivalTime);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
}
