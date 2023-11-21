#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
  int data;
  struct Node *next;
};

/* Function to reverse the linked list */
void reverseLinkedList (struct Node **head_addr)
{
  struct Node *prev = NULL;
  struct Node *current = *head_addr;
  struct Node *next = NULL;
  while (current != NULL)
    {
      // Store next 
      next = current->next;

      // Reverse current node's pointer 
      current->next = prev;

      // Move pointers one position ahead. 
      prev = current;
      current = next;
    }
  *head_addr = prev;
}

/* Function to push a node */
void insert (struct Node **head_addr, int new_data)
{
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));
  new_node->data = new_data;
  new_node->next = (*head_addr);
  (*head_addr) = new_node;
}

/* Function to print linked list */
void display (struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
    {
      printf ("%d  ", temp->data);
      temp = temp->next;
    }
}

int main ()
{
  int i, n, data;
  /* Start with the empty list */
  struct Node *head = NULL;
  printf ("Enter the number of nodes: ");
  scanf ("%d", &n);
  printf ("\nEnter the data in the nodes: ");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &data);
      insert (&head, data);
    }

  printf ("\nGiven linked list: ");
  reverseLinkedList (&head);
  display (head);

  printf ("\n\nReversed Linked list: ");
  reverseLinkedList (&head);
  display (head);

  return 0;
}