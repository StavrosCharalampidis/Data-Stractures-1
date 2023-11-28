#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 30

//Ylopoihsh Customer
typedef struct Customer{
    char name[QUEUE_SIZE];
    int clientNumber;
    int entranceTime;
    int front, rear, count;

} Customer;

Customer queue[QUEUE_SIZE];

// ypografes sinartiseon 
void enqueue(Customer customer);
void dequeue(Customer customer);
void displayCustomers(Customer customer);
int getCustomerCount(Customer customer);
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
        customer.front = customer.rear = customer.count = 0;
        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf(" %[^\n]s", customer.name);
                customer.clientNumber = clientNumber++;
                customer.entranceTime = time(NULL);
                enqueue(customer);
                break;
            case 2:
                dequeue(customer);
                break;
            case 3:
                displayCustomers(customer);
                break;
            case 4:
                printf("Number of customers in the queue: %d\n", getCustomerCount(customer));
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


void enqueue(Customer customer) {
    if (customer.count == QUEUE_SIZE) {
        printf("Queue is full. Cannot add customer.\n");
        return;
    }
    queue[customer.rear] = customer;
    customer.rear = (customer.rear + 1) % QUEUE_SIZE;
    customer.count++;
    printf("Customer %s entered the queue.\n", customer.name);
}

void dequeue(Customer customer) {
    if (customer.count == 0) {
        printf("Queue is empty. No customer to remove.\n");
        Customer emptyCustomer;
        strcpy(emptyCustomer.name, "");
        emptyCustomer.clientNumber = -1;
        emptyCustomer.entranceTime = -1;
        return emptyCustomer;
    }
    customer = queue[customer.front];
    customer.front = (customer.front + 1) % QUEUE_SIZE;
    customer.count--;
    printf("Customer %s exited the queue.\n", customer.name);
    return customer;
}

void displayCustomers(Customer customer) {
    printf("%-10s %-15s %-10s\n", "Number", "Name", "EntranceTime");
    for (int i = 0; i < customer.count; i++) {
        int index = (customer.front + i) % QUEUE_SIZE;
        printf("%-10d %-15s %-10d\n", queue[index].clientNumber, queue[index].name, queue[index].entranceTime);
    }
}

int getCustomerCount(Customer customer) {
    return customer.count;
}
