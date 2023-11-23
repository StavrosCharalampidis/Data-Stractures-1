#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Δομή για τον κόμβο της λίστας
struct MusicNode {
    char title[100];
    char artist[100];
    char genre[50];
    int duration;
    struct MusicNode* next;
};

// Δομή για την λίστα
struct MusicLibrary {
    struct MusicNode* head;
};

// Συνάρτηση για εισαγωγή μουσικού κομματιού στην λίστα
void insertSong(struct MusicLibrary* library) {
    struct MusicNode* newNode = (struct MusicNode*)malloc(sizeof(struct MusicNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter song title: ");
    scanf("%s", newNode->title);

    // Έλεγχος για τον τίτλο
    struct MusicNode* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, newNode->title) == 0) {
            printf("Song with the same title already exists. Cannot add.\n");
            free(newNode);
            return;
        }
        current = current->next;
    }

    printf("Enter artist: ");
    scanf("%s", newNode->artist);
    printf("Enter genre: ");
    scanf("%s", newNode->genre);
    printf("Enter duration (in seconds): ");
    scanf("%d", &newNode->duration);

    // Εισαγωγή στη λίστα
    newNode->next = library->head;
    library->head = newNode;

    printf("Song '%s' added to the library.\n", newNode->title);
}

// Συνάρτηση για αναζήτηση και εμφάνιση στοιχείων μουσικού κομματιού με συγκεκριμένο τίτλο
void searchByTitle(struct MusicLibrary* library, const char* title) {
    struct MusicNode* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %d seconds\n", current->duration);
            return;
        }
        current = current->next;
    }
    printf("Song with title '%s' not found.\n", title);
}

// Συνάρτηση για διαγραφή μουσικού κομματιού με συγκεκριμένο τίτλο
void deleteByTitle(struct MusicLibrary* library, const char* title) {
    struct MusicNode* current = library->head;
    struct MusicNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                library->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Song with title '%s' deleted.\n", title);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Song with title '%s' not found. Cannot delete.\n", title);
}

// Άλλες συναρτήσεις για τις υπόλοιπες λειτουργίες

int main() {
    struct MusicLibrary myLibrary;
    myLibrary.head = NULL;

    int choice;
    char title[100];

    do {
        printf("\nMenu:\n");
        printf("1. Insert a song\n");
        printf("2. Search by title\n");
        printf("3. Delete by title\n");
        // Προσθέστε περισσότερες επιλογές με βάση τις απαιτήσεις

        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertSong(&myLibrary);
                break;
            case 2:
                printf("Enter the title to search: ");
                scanf("%s", title);
                searchByTitle(&myLibrary, title);
                break;
            case 3:
                printf("Enter the title to delete: ");
                scanf("%s", title);
                deleteByTitle(&myLibrary, title);
                break;
            // Προσθέστε περισσότερες περιπτώσεις για τις υπόλοιπες λειτουργίες

            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
