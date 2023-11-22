#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ο καθορισμός της δομής για τον κόμβο της λίστας
typedef struct Node {
    char title[100];
    char artist[100];
    char genre[100];
    int duration;
    struct Node* prev;
    struct Node* next;
} Node;

// Οι δηλώσεις των συναρτήσεων που υλοποιούν τις λειτουργίες του μενού
void insertSong(Node** head);

void displayLibrary(Node* head) {
    Node *current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("-----------------------\n");
        current = current->next;
    }
}

int main() {
    // Δημιουργία της κενής λίστας
    Node* head = NULL;
    
    int choice;
    while (1) {
        printf("\n----------- Music Library -----------\n");
        printf("1. Insert Song\n");
        printf("2. Search Song\n");
        printf("3. Delete Song\n");
        printf("4. Delete Songs by Artist\n");
        printf("5. Print Count\n");
        printf("6. Print Library\n");
        printf("7. Print Total Duration\n");
        printf("8. Print Songs by Artist\n");
        printf("9. Print Songs by Genre\n");
        printf("10. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertSong(&head);
                break;
            case 2:
                displayLibrary(head);
                break;
            case 3:
                
                break;
        }
    }
    
    return 0;
}

// Υποσυνάρτηση για την δημιουργία και εισαγωγή ενός καινούριου κόμβου στην λίστα
void insertSong(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    printf("\nEnter song title: ");
    scanf(" %[^\n]s", newNode->title);
    
    // Έλεγχος αν υπάρχει ήδη το τραγούδι με αυτόν τον τίτλο
    if (*head == NULL || strcasecmp((*head)->title, newNode->title) > 0) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && strcasecmp(current->next->title, newNode->title) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
    
    printf("Song inserted successfully.\n");
}

// Υποσυνάρτηση για την αναζήτηση και εμφάνιση ενός τραγου
