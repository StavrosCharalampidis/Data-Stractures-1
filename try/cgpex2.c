#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MusicNode {
    char title[100];
    char artist[100];
    char genre[100];
    int duration;
    struct MusicNode* next;
    struct MusicNode* prev;
};

struct MusicLibrary {
    struct MusicNode* head;
};

void insert_music(struct MusicLibrary* library, const char* title, const char* artist, const char* genre, int duration) {
    struct MusicNode* new_node = (struct MusicNode*)malloc(sizeof(struct MusicNode));
    strcpy(new_node->title, title);
    strcpy(new_node->artist, artist);
    strcpy(new_node->genre, genre);
    new_node->duration = duration;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (library->head == NULL) {
        library->head = new_node;
    } else {
        struct MusicNode* current = library->head;
        while (current->next && strcasecmp(title, current->title) > 0) {
            current = current->next;
        }

        if (strcasecmp(title, current->title) <= 0) {
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

struct MusicNode* search_music(struct MusicLibrary* library, const char* title) {
    struct MusicNode* current = library->head;
    while (current) {
        if (strcasecmp(title, current->title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void delete_music(struct MusicLibrary* library, const char* title) {
    struct MusicNode* current = search_music(library, title);
    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            library->head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }

        free(current);
    }
}

void delete_by_artist(struct MusicLibrary* library, const char* artist) {
    struct MusicNode* current = library->head;
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

            struct MusicNode* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int count_music(struct MusicLibrary* library) {
    int count = 0;
    struct MusicNode* current = library->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void display_library(struct MusicLibrary* library) {
    struct MusicNode* current = library->head;
    while (current) {
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %d\n", current->title, current->artist, current->genre, current->duration);
        current = current->next;
    }
}

int total_duration(struct MusicLibrary* library) {
    int total = 0;
    struct MusicNode* current = library->head;
    while (current) {
        total += current->duration;
        current = current->next;
    }
    return total;
}

int main() {
    struct MusicLibrary library;
    library.head = NULL;

    insert_music(&library, "Ain’t No Sunshine", "Manu Chao", "Soul", 180);
    insert_music(&library, "Shape of My Heart", "Sting", "Pop", 240);
    insert_music(&library, "Clandestino", "Manu Chao", "Latin", 200);

    display_library(&library);

    printf("\nSearch for 'Ain’t No Sunshine':\n");
    struct MusicNode* result = search_music(&library, "Ain’t No Sunshine");
    if (result) {
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %d\n", result->title, result->artist, result->genre, result->duration);
    } else {
        printf("Music not found.\n");
    }

    printf("\nDelete 'Shape of My Heart':\n");
    delete_music(&library, "Shape of My Heart");
    display_library(&library);

    printf("\nDelete songs by artist 'Manu Chao':\n");
    delete_by_artist(&library, "Manu Chao");
    display_library(&library);

    printf("\nTotal number of songs in the library: %d\n", count_music(&library));
    printf("Total duration of all songs: %d\n", total_duration(&library));

    return 0;
}
