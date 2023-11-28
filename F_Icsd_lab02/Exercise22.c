#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MusicNode {
    char title[100];
    char artist[100];
    char genre[100];
    double duration;
    struct MusicNode* next;
    struct MusicNode* prev;
};

struct MusicLibrary {
    struct MusicNode* head;
};

void insert_music(struct MusicLibrary* library) {
    struct MusicNode *new_node = (struct MusicNode *) malloc(sizeof(struct MusicNode));
    if (new_node == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter music title to add: ");
    scanf("%s", new_node->title);
    // Έλεγχος για τον τίτλο
    struct MusicNode* current = library->head;
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
    //new_node->duration = duration;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (library->head == NULL) {
        library->head = new_node;
    } else {
        struct MusicNode* current = library->head;
        

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

void search_music(struct MusicLibrary* library, const char* title) {
    struct MusicNode* current = library->head;
    int found = 0;
    while (current) {
        if (strcasecmp(title, current->title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n",current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Duration: %lf seconds\n", current->duration);
            
        }
        current = current->next;
    }
    if (!found) {
        printf("No songs found for artist '%s'.\n", title);
    }
}

void displaySongsByArtist(struct MusicLibrary* library, const char* artist) {
    struct MusicNode* current = library->head;
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


struct MusicNode* SearchMusic(struct MusicLibrary* library, const char* title) {
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
    struct MusicNode* current = library->head;
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

            struct MusicNode* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
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
        printf("Title: %s, Artist: %s, Genre: %s, Duration: %lf\n", current->title, current->artist, current->genre, current->duration);
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
    
    (library).head = NULL;


    // Έλεγχος για τον τίτλο
    

    // printf("Enter artist: ");
    // scanf("%s", s->artist);
    // printf("Enter genre: ");
    // scanf("%s", s->genre);
    // printf("Enter duration (in seconds): ");
    // scanf("%lf", &s->duration);

    // insert_music(&library, s->title, s->artist, s->genre, s->duration);
    // insert_music(&library, s->title, s->artist, s->genre, s->duration);
    // insert_music(&library, s->title, s->artist, s->genre, s->duration);
    insert_music(&library);
    insert_music(&library);
    //display_library(&library);

    // printf("\nSearch for 'Ain’t No Sunshine':\n");
    // struct MusicNode* result = search_music(&library, "motto");
    // if (result) {
    //     printf("Title: %s, Artist: %s, Genre: %s, Duration: %lf\n", result->title, result->artist, result->genre, result->duration);
    // } else {
    //     printf("Music not found.\n");
    // }
    //
    // struct MusicNode *song = (struct MusicNode *) malloc(sizeof(struct MusicNode));
    // printf("Enter artist to display music by: ");
    // scanf("%s", song->artist);
    // displaySongsByArtist(&library, song->artist);
    

    //
    printf("\nDelete motto:\n");
    delete_music(&library, "motto");
    display_library(&library);

    // printf("\nDelete songs by artist nf:\n");
    // delete_by_artist(&library, "nf");
    // display_library(&library);

    printf("\nTotal number of songs in the library: %d\n", count_music(&library));
    printf("Total duration of all songs: %d\n", total_duration(&library));

    return 0;
}
