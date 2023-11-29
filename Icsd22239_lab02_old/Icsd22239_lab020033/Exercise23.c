//Christos Charalampidis icsd21071 
//Stavros Charalampidis icsd22239

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Δήλωση πινάκων για τις στοίβες
char product[MAX_PRODUCTS][50];
float value[MAX_PRODUCTS];
int top = -1;

// ypografes sinartiseon 
void push(char name[], float price);
void pop();

int main() {
    char action[4];

    do
    {
        printf("Eisagwgh (BUY, UNDO, END): ");
        scanf("%s", action);

        if (strcmp(action, "BUY") == 0)
        {
            char name[50];
            float price;

            printf("Eisagwgh omona proiovtos: ");
            scanf("%s", name);

            printf("Eisagwgh timis proiovtos: ");
            scanf("%f", &price);

            push(name, price);
        }
        else if (strcmp(action, "UNDO") == 0)
        {
            pop();
        }
        else if (strcmp(action, "END") != 0)
        {
            printf("lathos energia prospathiste ksana.\n");
        }
    } while (strcmp(action, "END") != 0);

    // Έλεγχος αν το καλάθι είναι άδειο
    if (top == -1)
    {
        printf("den exeis kamia agora\n");
    }
    else
    {
        float totalValue = 0;

        for (int i = 0; i <= top; i++)
        {
            totalValue += value[i];
        }

        printf("Plithos proiovtos: %d\n", top + 1);
        printf("Suvolikh aksia: %.2f\n", totalValue);

        // Έλεγχος για διαδοχικές αναιρέσεις
        int undoCount = 0;
        for (int i = 0; i < top; i++)
        {
            if (strcmp(product[i], product[i + 1]) == 0 && value[i] == value[i + 1])
            {
                undoCount++;
                top--; // Μείωση του μετρητή κατά ένα
            }
        }

        if (undoCount > 0)
        {
            printf("ekaves %d diadoxikes agores\n", undoCount);
        }
    }

    return 0;
}

// Συνάρτηση για εισαγωγή στοιχείου στη στοίβα
void push(char name[], float price)
{
    if (top < MAX_PRODUCTS - 1)
    {
        top++;
        strcpy(product[top], name);
        value[top] = price;
        printf("%s prosthethike sto kalathi me timi %.2f\n", name, price);
    }
    else
    {
        printf("to kalathi einai gemato\n");
    }
}

// Συνάρτηση για αφαίρεση στοιχείου από τη στοίβα
void pop()
{
    if (top >= 0)
    {
        printf("%s aferesi apo to kalathi\n", product[top]);
        top--;
    }
    else
    {
        printf("to kalathi einai adio\n");
    }
}
