#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Δήλωση πινάκων για τις στοίβες
char product[MAX_PRODUCTS][50];
float value[MAX_PRODUCTS];
int top = -1;

void push(char name[], float price);
void pop();

int main()
{
    char action[4];

    do
    {
        printf("Εισαγωγή ενέργειας (BUY, UNDO, END): ");
        scanf("%s", action);

        if (strcmp(action, "BUY") == 0)
        {
            char name[50];
            float price;

            printf("Εισαγωγή ονομασίας προϊόντος: ");
            scanf("%s", name);

            printf("Εισαγωγή τιμής προϊόντος: ");
            scanf("%f", &price);

            push(name, price);
        }
        else if (strcmp(action, "UNDO") == 0)
        {
            pop();
        }
        else if (strcmp(action, "END") != 0)
        {
            printf("Μη έγκυρη ενέργεια. Προσπαθήστε ξανά.\n");
        }
    } while (strcmp(action, "END") != 0);

    // Έλεγχος αν το καλάθι είναι άδειο
    if (top == -1)
    {
        printf("Δεν πραγματοποιήθηκαν αγορές\n");
    }
    else
    {
        float totalValue = 0;

        for (int i = 0; i <= top; i++)
        {
            totalValue += value[i];
        }

        printf("Πλήθος προϊόντων: %d\n", top + 1);
        printf("Συνολική αξία: %.2f\n", totalValue);

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
            printf("Πραγματοποιήθηκαν %d διαδοχικές αναιρέσεις αγορών\n", undoCount);
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
        printf("%s προστέθηκε στο καλάθι με τιμή %.2f\n", name, price);
    }
    else
    {
        printf("Το καλάθι αγορών είναι γεμάτο\n");
    }
}

// Συνάρτηση για αφαίρεση στοιχείου από τη στοίβα
void pop()
{
    if (top >= 0)
    {
        printf("%s αφαιρέθηκε από το καλάθι\n", product[top]);
        top--;
    }
    else
    {
        printf("Το καλάθι αγορών είναι άδειο\n");
    }
}