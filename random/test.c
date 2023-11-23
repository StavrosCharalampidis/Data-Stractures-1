#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Δήλωση της δομής για το μουσικό κομμάτι
typedef struct song {
    char title[100];
    char artist[100];
    char genre[100];
    int duration;
    struct song *prev;
    struct song *next;
} Song;

// Δήλωση της δομής για τη μουσική βιβλιοθήκη
typedef struct library {
    Song *head;
    Song *tail;
    int count;
} Library;

// Πρωτότυπα συναρτήσεων
void initLibrary(Library *library);
void addSong(Library *library);
void searchSong(Library *library);
void deleteSong(Library *library);
void deleteSongsByArtist(Library *library);
void displayNumOfSongs(Library *library);
void displayLibrary(Library *library);
void displayTotalDuration(Library *library);
void displaySongsByArtist(Library *library);
void displaySongsByGenre(Library *library);

int main() {
    int choice;
    Library library;
    
    initLibrary(&library);
    
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
                searchSong(&library);
                break;
            case 3:
                deleteSong(&library);
                break;
            case 4:
                deleteSongsByArtist(&library);
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
                displaySongsByArtist(&library);
                break;
            case 9:
                printf("Exiting program...\n");
                displaySongsByGenre(&library);
                break;
            
            case 10:
                exit(0);
                break;
        }
    }

    return 1;
}

void initLibrary(Library *library){};
void addSong(Library *library){};
void searchSong(Library *library){};
void deleteSong(Library *library){};
void deleteSongsByArtist(Library *library){};
void displayNumOfSongs(Library *library){};
void displayLibrary(Library *library){};
void displayTotalDuration(Library *library){};
void displaySongsByArtist(Library *library){};
void displaySongsByGenre(Library *library){};