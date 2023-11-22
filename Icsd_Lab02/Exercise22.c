// icsd
#include <stdlib.h>
#include <stdio.h>


typedef struct Doubly_Linked_List
{
    const char *data;
    struct Doubly_Linked_List *next;
    struct Doubly_Linked_List *prev;
} D_Node;

typedef struct Music_Library{
    const char *title;
    const char *artist[10];
    const char *eidos;
    double time;

} Music_Library;

int main(int argc, char const *argv[]) {

    return 0;
}
