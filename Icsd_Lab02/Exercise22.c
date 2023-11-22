// icsd
#include <stdlib.h>
#include <stdio.h>
#define N 10
typedef struct Music_Library {
    const char *title[N];
    const char *artist[N];
    const char *eidos[N];
    double time;

} Music_Library;

typedef struct Doubly_Linked_List {
    int count;
    Music_Library *head;
    Music_Library *tail;
} D_Node;


int main(int argc, char const *argv[]) {

    return 0;
}
