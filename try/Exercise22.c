#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

typedef struct Music_Library {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    double duration;

    int count;
    struct Music_Library *next;
    struct Music_Library *prev;
} Music_Library;


void addSong1(Music_Library **head, Music_Library **tail, const char * position);

void print(Music_Library **head, Music_Library **tail);

// Function prototypes
void addSong(Music_Library* library);
void searchSong(Music_Library* library, const char* title);
void deleteSong(Music_Library* library, const char* title);
void deleteSongsByArtist(Music_Library* library, const char* artist);
void displayNumOfSongs(Music_Library* library);
void displayLibrary(Music_Library* library);
void displayTotalDuration(Music_Library* library);
void displaySongsByArtist(Music_Library* library, const char* artist);
void displaySongsByGenre(Music_Library* library, const char* genre);
int main(int argc, char const *argv[]) {
    
   
        printf("\n=== ΜΟΥΣΙΚΗ ΒΙΒΛΙΟΘΗΚΗ ===\n");
        printf("1. Εισαγωγή μουσικού κομματιού\n");
        printf("2. Αναζήτηση και εμφάνιση στοιχείων μουσικού κομματιού\n");
        printf("3. Διαγραφή μουσικού κομματιού\n");
        printf("4. Διαγραφή μουσικών κομματιών με βάση τον τραγουδιστή\n");
        printf("5. Εμφάνιση πλήθους μουσικών κομματιών\n");
        printf("6. Εμφάνιση ολόκληρης της μουσικής βιβλιοθήκης\n");
        printf("7. Εμφάνιση συνολικής διάρκειας όλων των μουσικών κομματιών\n");
        printf("8. Εμφάνιση όλων των μουσικών κομματιών ενός τραγουδιστή\n");
        printf("9. Εμφάνιση όλων των μουσικών κομματιών συγκεκριμένου είδους\n");
        printf("10. Έξοδος\n");
        printf("Επιλέξτε μια επιλογή: ");
        //scanf("%d", &choice);
        Music_Library *song = (Music_Library *) malloc(sizeof(Music_Library));
        if (song == NULL) {
            printf("Memory allocation error.\n");
            return 1;
        }
        Music_Library *head = NULL;
        Music_Library *tail = NULL;
        addSong1(&head, &tail,"head");
        print(&head, &tail);
        return 0;
}
void addSong1(Music_Library **head, Music_Library **tail, const char * position){
    if (position == NULL || (strcmp(position, "head") != 0 && strcmp(position, "tail") != 0)) {
        printf("Mh egkurh thesh 'head' h 'tail'.\n");
        return;
    }
    Music_Library *newNode = (Music_Library *)malloc(sizeof(Music_Library));
    // Prompt the user to enter the title of the song
    printf("Enter music title to add: ");
    scanf("%s", newNode->title);

    // Check if a song with the same title already exists in the library
    Music_Library* current = newNode->next;
    while (current != NULL) {
        if (strcmp(current->title, newNode->title) == 0) {
            printf("Song with the same title already exists. Cannot add.\n");
            free(newNode);
            return;
        }
        current = current->prev;
    }

    
    printf("Enter artist: ");
    scanf("%s", newNode->artist);
    printf("Enter genre: ");
    scanf("%s", newNode->genre);
    printf("Enter duration (in seconds): ");
    scanf("%lf", &newNode->duration);

    //newNode->prev = newNode->next;
    newNode->prev, newNode->next = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
        (*head)->prev = NULL;  
        return;  
    }

    else {
       
        if (strcmp(position, "head") == 0) {
            newNode -> prev = NULL;
            newNode -> next = *head;
            (*head) -> prev = newNode;
            *head = newNode;
            return; 
        }
        else {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;           
            return; 
        }
        

    }
    
}


void print(Music_Library **head, Music_Library **tail) {
    Music_Library *current;
    if (*head == NULL){
        printf("List is Empty!\n");
    }
    else {
        current = *tail;
        while (current != NULL) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %f seconds\n", current->duration);
            printf("-----------------------\n");
            current = current -> prev;
        }
    }
}
