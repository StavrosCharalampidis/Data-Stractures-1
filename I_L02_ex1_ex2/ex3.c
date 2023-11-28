#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertEnd(struct Node** head, int data){
    
    // since this will be the last node so it will point to NULL
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // if Linked List is empty its is first node being entered
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // otherwise find the current last node
    
    // create another variable to traverse the LL
    // *head should not be used as we do not want to change head
    struct Node* temp = *head;
    
    // traverse to the last node of Linked List
    while(temp->next!=NULL)
        temp = temp->next;
    
    // assign last node's next to this newNode
    temp->next = newNode;

}

void deleteStart (struct Node **head)
{
  struct Node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // move head to next node
  *head = (*head)->next;
  printf ("Deleted: %d\n", temp->data);
  free (temp);
}

void display (struct Node *node)
{

  // as linked list will end when Node is Null
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}



///////////////////////////////



int main ()
{

  struct Node *head = NULL;

  printf ("Linked List: ");
  insertEnd (&head, 6);
  insertEnd (&head, 5);
  //deleteStart (&head);

  insertEnd (&head, 4);
  insertEnd (&head, 3);
  insertEnd (&head, 2);
  insertEnd (&head, 1);
  insertEnd (&head, 10);
  deleteStart (&head);

  display (head);

  return 0;
}