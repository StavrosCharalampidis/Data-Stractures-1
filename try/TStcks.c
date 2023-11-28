#include<stdio.h>
#include<stdlib.h>

struct p
{
    char product[50];
    struct p *next;
};

//struct p *head = NULL;

struct v {
    double value;
    struct v *next;
};

struct v *head = NULL;

void push(int val) {
    //create new node
    struct v *newNode = (int *) malloc (1 * sizeof (int));
    newNode->value = val;

    //make the new node points to the head node
    newNode->next = head;

    //make the new node as head node
    //so that head will always point the last inserted data
    head = newNode;
}

void pop() {
    //temp is used to free the head node
    struct v *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %f\n", head->value);

        //backup the head node
        temp = head;

        //make the head node points to the next node.
        //logically removing the node
        head = head->next;

        //free the poped element's memory
        free(temp);
    }
}

//print the linked list
void display()
{
    struct v *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%lf->", temp->value);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    push(10.7);
    push(20);
    push(30);
    printf("Linked List\n");
    display();
    

    return 0;
}