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

void print(Music_Library *head);

int main(int argc, char const *argv[]) {
    
        Music_Library *song = (Music_Library *) malloc(sizeof(Music_Library));
        if (song == NULL) {
            printf("Memory allocation error.\n");
            return 1;
        }
        Music_Library *head = NULL;
        Music_Library *tail = NULL;
        addSong1(&head, &tail,"head");
        addSong1(&head, &tail,"head");
        print(head);
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
            (*head) = newNode -> next;
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


void print(Music_Library *head) {
    while (head != NULL) {
            head = head ->prev;
            printf("Title: %s\n", head->title);
            printf("Artist: %s\n", head->artist);
            printf("Genre: %s\n", head->genre);
            printf("Duration: %f seconds\n", head->duration);
            printf("-----------------------\n");
            head = head -> next;
        }
}

