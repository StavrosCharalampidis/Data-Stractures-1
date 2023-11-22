#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

void push(char stack[][MAX_SIZE], int *top, char *item);
void pop(char stack[][MAX_SIZE], int *top, char *item);

int main() {
    char products[MAX_SIZE][MAX_SIZE];
    int prices[MAX_SIZE];
    int top = -1;
    int total = 0;
    int undo_count = 0;
    char operation[5];
    char product[MAX_SIZE];
    int price;
    
    while (1) {
        printf("Enter operation (BUY, UNDO, END): ");
        scanf("%s", operation);
        
        if (strcmp(operation, "BUY") == 0) {
            if (top == MAX_SIZE - 1) {
                printf("The shopping cart is full.\n");
            } else {
                printf("Enter product name: ");
                scanf("%s", product);
                printf("Enter product price: ");
                scanf("%d", &price);
                
                push(products, &top, product);
                prices[top] = price;
                total += price;
            }
        } else if (strcmp(operation, "UNDO") == 0) {
            if (top == -1) {
                printf("The shopping cart is empty.\n");
            } else {
                char last_product[MAX_SIZE];
                pop(products, &top, last_product);
                int last_price = prices[top + 1];
                total -= last_price;
            }
            
            if (undo_count == 1) {
                undo_count = 0;
            } else {
                undo_count++;
            }
        } else if (strcmp(operation, "END") == 0) {
            break;
        } else {
            printf("Invalid operation.\n");
        }
    }
    
    if (top == -1) {
        printf("No purchases were made.\n");
    } else {
        printf("Number of products: %d\n", top + 1);
        printf("Total value: %d\n", total);
    }
    
    if (undo_count > 0) {
        printf("Number of consecutive UNDO operations: %d\n", undo_count);
    }

    return 0;
}

void push(char stack[][MAX_SIZE], int *top, char *item) {
    (*top)++;
    strcpy(stack[*top], item);
}

void pop(char stack[][MAX_SIZE], int *top, char *item) {
    strcpy(item, stack[*top]);
    (*top)--;
}