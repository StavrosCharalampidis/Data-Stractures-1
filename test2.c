#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int duration;
    struct Music *prev;
    struct Music *next;
};

struct Music *library = NULL;

void insertMusic() {
    struct Music *newMusic = malloc(sizeof(struct Music));
    printf("Enter music title: ");
    scanf("%s", newMusic->title);
    printf("Enter artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter duration (in seconds): ");
    scanf("%d", &newMusic->duration);
    newMusic->prev = NULL;
    newMusic->next = NULL;

    if (library == NULL) {
        library = newMusic;
    } else {
        struct Music *current = library;
        while (current != NULL) {
            int cmp = strcmp(newMusic->title, current->title);
            if (cmp < 0) {
                if (current->prev != NULL) {
                    current->prev->next = newMusic;
                    newMusic->prev = current->prev;
                } else {
                    library = newMusic;
                }
                newMusic->next = current;
                current->prev = newMusic;
                return;
            }
            if (current->next == NULL) {
                current->next = newMusic;
                newMusic->prev = current;
                return;
            }
            current = current->next;
        }
    }
}

void searchMusic() {
    char title[50];
    printf("Enter music title to search: ");
    scanf("%s", title);

    struct Music *current = library;
    while (current != NULL) {
        if (strcmp(title, current->title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %d seconds\n", current->duration);
            return;
        }
        current = current->next;
    }

    printf("Music not found.\n");
}

void deleteMusic() {
    char title[50];
    printf("Enter music title to delete: ");
    scanf("%s", title);

    struct Music *current = library;
    while (current != NULL) {
        if (strcmp(title, current->title) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                library = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Music deleted.\n");
            return;
        }
        current = current->next;
    }

    printf("Music not found.\n");
}

void deleteByArtist() {
    char artist[50];
    printf("Enter artist to delete music by: ");
    scanf("%s", artist);

    struct Music *current = library;
    while (current != NULL) {
        if (strcmp(artist, current->artist) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                library = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            current = library;
        } else {
            current = current->next;
        }
    }

    printf("Music deleted.\n");
}

void displayCount() {
    int count = 0;
    struct Music *current = library;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Number of music pieces: %d\n", count);
}

void displayLibrary() {
    struct Music *current = library;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("Duration: %d seconds\n", current->duration);
        printf("-----------------------\n");
        current = current->next;
    }
}

void displayTotalDuration() {
    int totalDuration = 0;
    struct Music *current = library;
    while (current != NULL) {
        totalDuration += current->duration;
        current = current->next;
    }
    printf("");
}
