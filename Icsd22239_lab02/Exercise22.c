#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ylopoihsh Music Song
typedef struct Music_Song {
    char title[100];
    char artist[100];
    char genre[100];
    double duration;
    struct Music_Song* next;
    struct Music_Song* prev;
} Music_Song;

//Ylopoihsh Music Library
typedef struct Music_Library {
    Music_Song* head;
} Music_Library;

//Ypografes sinartiseon
void addSong(Music_Library* library);
void searchSong(Music_Library* library, const char* title);
void deleteSong(Music_Library* library, const char* title);
void deleteSongsByArtist(Music_Library* library, const char* artist);
int displayNumOfSongs(Music_Library* library);
void displayLibrary(Music_Library* library);
int displayTotalDuration(Music_Library* library);
void displaySongsByArtist(Music_Library* library, const char* artist);
void displaySongsByGenre(Music_Library* library, const char* genre);



int main() {
    

    //
    int choice;
    Music_Library library;
    (library).head = NULL;
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
                printf("\nTotal number of songs in the library: %d\n", displayNumOfSongs(&library));
                break;
            case 6:
                displayLibrary(&library);
                break;
            case 7:
                
                printf("Total duration of all songs: %d\n", displayTotalDuration(&library));
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
    Music_Song *new_node = (Music_Song *) malloc(sizeof(Music_Song));
    if (new_node == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter music title to add: ");
    scanf("%s", new_node->title);
    // elegxos gia titlo
    Music_Song* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, new_node->title) == 0) {
            printf("Song with the same title already exists. Cannot add.\n");
            free(new_node);
            return;
        }
        current = current->prev;
    }

    printf("Enter artist: ");
    scanf("%s", new_node->artist);
    printf("Enter genre: ");
    scanf("%s", new_node->genre);
    printf("Enter duration (in seconds): ");
    scanf("%lf", &new_node->duration);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (library->head == NULL) {
        library->head = new_node;
    } else {
        Music_Song* current = library->head;
        

        while (current->next && strcmp(new_node->title, current->title) > 0) {
            current = current->next;
        }

        if (strcmp(new_node->title, current->title) <= 0) {
            if (current->prev) {
                current->prev->next = new_node;
                new_node->prev = current->prev;
            } else {
                library->head = new_node;
            }
            new_node->next = current;
            current->prev = new_node;
        } else {
            current->next = new_node;
            new_node->prev = current;
        }
    }
}

void searchSong(Music_Library* library, const char* title) {
    Music_Song* current = library->head;
    int found = 0;
    while (current) {
        if (strcasecmp(title, current->title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n",current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %lf seconds\n", current->duration);
            found = 1;
        }
        current = current->next;
    }
if (!found) {
        printf("No songs found for artist '%s'.\n", title);
    }
}

void displaySongsByArtist(Music_Library* library, const char* artist) {
    Music_Song* current = library->head;
    int found = 0;

    while (current) {
        if (strcmp(current->artist, artist) == 0) {
            printf("Title: %s\n", current->title);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %lf seconds\n", current->duration);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No songs found for artist '%s'.\n", artist);
    }
}

void displaySongsByGenre(Music_Library* library, const char* genre) {
    Music_Song* current = library->head;
    int found = 0;

    while (current) {
        if (strcmp(current->genre, genre) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Duration: %lf seconds\n", current->duration);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No songs found for artist '%s'.\n", genre);
    }
}

void deleteSong(Music_Library* library, const char* title) {
    Music_Song* current = library->head;
    while (current) {
        if (strstr(current->title, title) != NULL) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                library->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }

            Music_Song* temp = current;
            current = current->next;
            free(temp);
            printf("Song with title '%s' deleted.\n", title);
        } else {
            current = current->next;
            printf("Song with title '%s' not found. Cannot delete.\n", title);
        }
    }
    
}

void deleteSongsByArtist(Music_Library* library, const char* artist) {
    Music_Song* current = library->head;
    while (current) {
        if (strstr(current->artist, artist) != NULL) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                library->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }

            Music_Song* temp = current;
            current = current->next;
            free(temp);
            printf("Song with title '%s' deleted.\n", artist);
        } else {
            current = current->next;
            printf("Song with title '%s' not found. Cannot delete.\n", artist);
        }
    }
     
}

int displayNumOfSongs(Music_Library* library) {
    int count = 0;
    Music_Song* current = library->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}



void displayLibrary(Music_Library* library) {
    Music_Song* current = library->head;
    while (current) {
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %lf\n", current->title, current->artist, current->genre, current->duration);
        current = current->next;
    }
}

int displayTotalDuration(Music_Library* library) {
    int total = 0;
    Music_Song* current = library->head;
    while (current) {
        total += current->duration;
        current = current->next;
    }
    return total;
}

