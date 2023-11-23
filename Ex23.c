#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Δομή για κάθε προϊόν
typedef struct Product {
    char name[50];
    float value;
    struct Product *next;
} Product;

// Δομή για το καλάθι αγορών
typedef struct ShoppingCart {
    Product *top;
} ShoppingCart;

// Συνάρτηση για εισαγωγή προϊόντος στο καλάθι
void buyProduct(ShoppingCart *cart, const char *name, float value) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    if (newProduct == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    strcpy(newProduct->name, name);
    newProduct->value = value;
    newProduct->next = cart->top;
    cart->top = newProduct;

    printf("Προστέθηκε στο καλάθι αγορών: %s, Τιμή: %.2f\n", name, value);
}

// Συνάρτηση για αφαίρεση τελευταίου προϊόντος από το καλάθι
void undoLastPurchase(ShoppingCart *cart) {
    if (cart->top != NULL) {
        Product *temp = cart->top;
        cart->top = temp->next;
        printf("Αφαιρέθηκε από το καλάθι αγορών: %s, Τιμή: %.2f\n", temp->name, temp->value);
        free(temp);
    } else {
        printf("Το καλάθι αγορών είναι άδειο.\n");
    }
}

// Συνάρτηση για εμφάνιση πληροφοριών του καλαθιού αγορών
void displayCartInfo(ShoppingCart *cart) {
    if (cart->top != NULL) {
        float totalValue = 0;
        int undoCount = 0;

        Product *current = cart->top;
        while (current != NULL) {
            totalValue += current->value;
            undoCount++;
            current = current->next;
        }

        printf("Πλήθος προϊόντων στο καλάθι αγορών: %d\n", undoCount);
        printf("Συνολική αξία: %.2f\n", totalValue);
        printf("Πλήθος αναιρέσεων: %d\n", undoCount - 1);
    } else {
        printf("Δεν πραγματοποιήθηκαν αγορές.\n");
    }
}

// Συνάρτηση για αποδέσμευση της μνήμης του καλαθιού αγορών
void freeShoppingCart(ShoppingCart *cart) {
    Product *current = cart->top;
    while (current != NULL) {
        Product *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    ShoppingCart cart;
    cart.top = NULL;

    char action[5];

    do {
        printf("\nΕπιλέξτε κίνηση (BUY, UNDO, END): ");
        scanf("%s", action);

        if (strcmp(action, "BUY") == 0) {
            char product[50];
            float value;

            printf("Εισάγετε όνομα προϊόντος: ");
            scanf("%s", product);

            printf("Εισάγετε τιμή προϊόντος: ");
            scanf("%f", &value);

            buyProduct(&cart, product, value);
        } else if (strcmp(action, "UNDO") == 0) {
            undoLastPurchase(&cart);
        } else if (strcmp(action, "END") != 0) {
            printf("Μη έγκυρη ενέργεια. Προσπαθήστε ξανά.\n");
        }
    } while (strcmp(action, "END") != 0);

    displayCartInfo(&cart);

    // Αποδέσμευση μνήμης του καλαθιού αγορών
    freeShoppingCart(&cart);

    return 0;
}