#include <stdio.h>
#include <stdlib.h>

struct node
{
    char *data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(char *d) // Insert elements in Queue
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if ((r == NULL) && (f == NULL))
    {
        f = r = n;
        r->next = f;
    }
    else
    {
        r->next = n;
        r = n;
        n->next = f;
    }
}

void dequeue() // Delete an element from Queue
{
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else if (f == r)
    {
        f = r = NULL;
        free(t);
    }
    else
    {
        f = f->next;
        r->next = f;
        free(t);
    }
}

void display()
{ // Print the elements of Queue
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else
    {
        do
        {
            printf(" %s", t->data);
            t = t->next;
        } while (t != f);
    }
}

int main()
{
    enqueue("a");
    enqueue("w");
    enqueue("e");
    enqueue("r");
    enqueue("t");
    printf("Circular Queue: ");
    display();
    printf("\n");

    dequeue();
    printf("Circular Queue After dequeue: ");
    display();
    return 0;
}