#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 30

typedef struct Customer{
    char name[QUEUE_SIZE];
    int clientNumber;
    int entranceTime;

} Customer;


Customer queue[QUEUE_SIZE];
int rear = 0;
int front = 0;
int count = 0;


void enqueue(Customer customer) {
    if (((rear + 1) % QUEUE_SIZE) == front) {
        printf("Queue is full. Cannot add customer.\n");
        return;
    }
    queue[rear] = customer;
    rear = (rear + 1) % QUEUE_SIZE;
    
    count++;
    printf("Customer %s entered the queue.\n", customer.name);
}

Customer dequeue() {
    if (front == rear) {
        printf("Queue is empty. No customer to remove.\n");
        Customer emptyCustomer;
        strcpy(emptyCustomer.name, "");
        emptyCustomer.clientNumber = -1;
        emptyCustomer.entranceTime = -1;
        return emptyCustomer;
    }
    Customer customer = queue[front];
    front = (front + 1) % QUEUE_SIZE;
    count--;
    printf("Customer %s exited the queue.\n", customer.name);
    return customer;
}

void displayCustomers() {
    printf("%-10s %-15s %-10s\n", "Number", "Name", "EntranceTime");
    for (int i = 0; i < count; i++) {
        int index = (front + i) % QUEUE_SIZE;
        printf("%-10d %-15s %-10d\n", queue[index].clientNumber, queue[index].name, queue[index].entranceTime);
    }
}

int getCustomerCount() {
    return count;
}

int main() {
    int choice;
    int clientNumber = 1;
    
    while (1) {
        printf("\nMENU\n");
        printf("=====\n");
        printf("1. Enter customer into the queue.\n");
        printf("2. Exit customer from the queue.\n");
        printf("3. Display customer details in the queue.\n");
        printf("4. Number of customers in the queue.\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        Customer customer;
        
        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf(" %s", customer.name);
                customer.clientNumber = clientNumber++;
                customer.entranceTime = rand() % 10 + 1;
                enqueue(customer);
                break;
            case 2:
                customer = dequeue();
                break;
            case 3:
                displayCustomers();
                break;
            case 4:
                printf("Number of customers in the queue: %d\n", getCustomerCount());
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}