#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Υλοποίηση στοίβας με πίνακες
typedef struct {
    char products[MAX_PRODUCTS][50];  // Ονομασίες προϊόντων
    float prices[MAX_PRODUCTS];       // Τιμές προϊόντων
    int top;                          // Επόμενη διαθέσιμη θέση στη στοίβα
} ShoppingCart;

// Συνάρτηση για εισαγωγή προϊόντος στη στοίβα
void push(ShoppingCart *cart, char* product, float price) {
    if (cart->top >= MAX_PRODUCTS) {
        printf("Το καλάθι αγορών είναι γεμάτο.\n");
    } else {
        strcpy(cart->products[cart->top], product);
        cart->prices[cart->top] = price;
        cart->top++;
    }
}

// Συνάρτηση για αφαίρεση προϊόντος από τη στοίβα
void pop(ShoppingCart *cart) {
    if (cart->top <= 0) {
        printf("Το καλάθι είναι άδειο.\n");
    } else {
        cart->top--;
    }
}

// Βοηθητική συνάρτηση για τον υπολογισμό της άθροισης των τιμών
float calculateTotalPrice(ShoppingCart *cart) {
    float total = 0;
    for (int i = 0; i < cart->top; i++) {
        total += cart->prices[i];
    }
    return total;
}

int main() {
    ShoppingCart cart;
    cart.top = 0;  // Αρχικοποίηση μεταβλητής top

    char action[10];
    char product[50];
    float price;

    do {
        printf("\nΕπιλέξτε κίνηση (BUY, UNDO, END): ");
        scanf("%s", action);

        if (strcmp(action, "BUY") == 0) {
            printf("Εισάγετε την ονομασία του προϊόντος: ");
            scanf("%s", product);
            printf("Εισάγετε την τιμή του προϊόντος: ");
            scanf("%f", &price);

            push(&cart, product, price);
        } else if (strcmp(action, "UNDO") == 0) {
            pop(&cart);
        }
    } while (strcmp(action, "END") != 0);

    if (cart.top == 0) {
        printf("Δεν πραγματοποιήθηκαν αγορές.\n");
    } else {
        printf("Πλήθος προϊόντων: %d\n", cart.top);
        printf("Συνολική αξία: %.2f\n", calculateTotalPrice(&cart));
    }

    return 0;
}