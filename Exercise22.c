#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

typedef struct Music_Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    double duration;
    struct Music_Song* tail;
} Music_Song;

typedef struct Music_Library {
    int count;
    Music_Song* head;
} Music_Library;

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
    int choice;
    Music_Library library;
    Music_Song *song = (Music_Song *) malloc(sizeof(Music_Song));
    if (song == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }
    
    while (1) {
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
        scanf("%d", &choice);

        switch (choice) {
            case 1:   
                addSong(&library);
                break;
            case 2:
                printf("Enter music title to search: ");
                scanf("%s", song->title);
                searchSong(&library, song->title);
                break;
            case 3:
                printf("Enter music title to delete: ");
                scanf("%s", song->title);
                deleteSong(&library, song->title);
                break;
            case 4:
                printf("Enter artist to delete music by: ");
                scanf("%s", song->artist);
                deleteSongsByArtist(&library, song->artist);
                break;
            case 5:
                displayNumOfSongs(&library);
                break;
            case 6:
                displayLibrary(&library);
                break;
            case 7:
                displayTotalDuration(&library);
                break;
            case 8:
                printf("Enter artist to display music by: ");
                scanf("%s", song->artist);
                displaySongsByArtist(&library, song->artist);
                break;
            case 9:
                printf("Enter genre to display music by: ");
                scanf("%s", song->genre);
                displaySongsByGenre(&library, song->genre);
                break;
            
            case 10:
                printf("Exiting program...\n");
                exit(0);
                break;
        }
    }

    return 0;
}

void addSong(Music_Library* library) {
    // Allocate memory for a new Music_Song node
    Music_Song* newNode = (Music_Song*)malloc(sizeof(Music_Song));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Prompt the user to enter the title of the song
    printf("Enter music title to add: ");
    scanf("%s", newNode->title);

    // Check if a song with the same title already exists
    Music_Song* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, newNode->title) == 0) {
            printf("Song with the same title already exists. Cannot add.\n");
            free(newNode);
            return;
        }
        current = current->tail;
    }

    // Prompt the user to enter the artist, genre, and duration of the song
    printf("Enter artist: ");
    scanf("%s", newNode->artist);
    printf("Enter genre: ");
    scanf("%s", newNode->genre);
    printf("Enter duration (in seconds): ");
    scanf("%lf", &newNode->duration);

    // Add the new node to the beginning of the linked list
    newNode->tail = library->head;
    library->head = newNode;

    printf("Song '%s' added to the library.\n", newNode->title);
}

void searchSong(Music_Library* library, const char* title) {
    Music_Song* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %f seconds\n", current->duration);
            return;
        }
        current = current->tail;
    }
    printf("Song with title '%s' not found.\n", title);
}

void deleteSong(Music_Library* library, const char* title) {
    Music_Song* current = library->head;
    Music_Song* head = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (head == NULL) {
                library->head = current->tail;
            } else {
                head->tail = current->tail;
            }
            free(current);
            printf("Song with title '%s' deleted.\n", title);
            return;
        }
        head = current;
        current = current->tail;
    }

    printf("Song with title '%s' not found. Cannot delete.\n", title);
}

void displayLibrary(Music_Library* library) {
    Music_Song* current = library->head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("Duration: %f seconds\n", current->duration);
        printf("-----------------------\n");
        current = current->tail;
    }
}
// Function to delete songs by artist
void deleteSongsByArtist(Music_Library* library, const char* artist) {
    Music_Song* current = library->head;
    Music_Song* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->artist, artist) == 0) {
            if (prev == NULL) {
                library->head = current->tail;
            } else {
                prev->tail = current->tail;
            }
            free(current);
            current = library->head;
        } else {
            prev = current;
            current = current->tail;
        }
    }

    printf("Songs by artist '%s' deleted.\n", artist);
}

// Function to display the total number of songs
void displayNumOfSongs(Music_Library* library) {
    int totalSongs = 0;
    Music_Song* current = library->head;

    while (current != NULL) {
        totalSongs++;
        current = current->tail;
    }

    printf("Total Songs: %d\n", totalSongs);
}

// Function to display the total duration of all songs
void displayTotalDuration(Music_Library* library) {
    double totalDuration = 0;
    Music_Song* current = library->head;

    while (current != NULL) {
        totalDuration += current->duration;
        current = current->tail;
    }

    printf("Total Duration: %lf seconds\n", totalDuration);
}

// Function to display songs by artist
void displaySongsByArtist(Music_Library* library, const char* artist) {
    Music_Song* current = library->head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->artist, artist) == 0) {
            printf("Title: %s\n", current->title);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %lf seconds\n", current->duration);
            found = 1;
        }
        current = current->tail;
    }

    if (!found) {
        printf("No songs found for artist '%s'.\n", artist);
    }
}
void displaySongsByGenre(Music_Library* library, const char* genre) {
    Music_Song* current = library->head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->genre, genre) == 0) {
            printf("Title: %s\nArtist: %s\nDuration: %lf seconds\n", current->title, current->artist, current->duration);
            found = 1;
        }
        current = current->tail;
    }

    if (!found) {
        printf("No songs found for genre '%s'.\n", genre);
    }
}