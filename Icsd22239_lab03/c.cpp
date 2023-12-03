#include <iostream>
#include <stdlib.h>

using namespace std;

//Ç äïìÞ ôïõ äÝíôñïõ
typedef struct node{
    int number;
    node *Left, *Right;
}Node;

Node *head = NULL;

//ÄÞëùóç óõíáñôÞóåùí
int menu_option();
int CreateAndInsert(Node **, int);
void printInOrder(Node *);
int InsertAtTree(Node **, Node *);


int main(){
    int action=0;

    do{
        action = menu_option();
        switch(action){
            case 1:
                int number;

                cout<<"Enter Number: ";
                cin >> number;

                if(CreateAndInsert(&head, number) != -1)
                    cout<<"\nRegistration completed"<<endl;
                else
                    cout<<"\nRegistration failed"<<endl;
                break;
            case 2:
                if(head==NULL)
                    cout<<"\nTree is empty!";
                else
                    printInOrder(head);
                break;
            case 0:
                break;
        }
        cout<<"\n\n\n";
    }while(action!=0);
}



//žêôýðùóç óôïé÷åßùí âÜóç åíäïäéáôåôáãìÝíçò äéÜôáîçò
void printInOrder(Node *ptrhead) {
    // ...
}


//ÅéóÜãåé óôïé÷åßá óôï äÝíôñï
int CreateAndInsert(Node **ptrhead, int ID){
    Node *NewNode = (Node*)malloc(sizeof(Node)); // Äåóìåýåé ÷þñï ãéá ôïí êáéíïýñãéï êüìâï.
    if(NewNode==NULL)
        return -1;

    NewNode->number=ID;
    NewNode->Left=NULL;
    NewNode->Right=NULL;

    if(InsertAtTree(ptrhead, NewNode)==-1){
        cout<<endl<<"The node already exists";
        delete NewNode;
        return -1;
    }
    return 0;
}

//ÅéóáãùãÞ óôï äÝíäñï
int InsertAtTree(Node **ptrhead, Node *newNode) {
    // Êáôá÷þñçóç óôï äÝíäñï âÜóç ôïõ áñéèìïý
    //...
	}

//Åìöáíßæåé ôï ìåíïý êáé åðéóôñÝöåé ôçí åðéëïãÞ ôïõ ÷ñÞóôç.
int menu_option(){
    cout << "##################################################################";
    cout << "\n#                              MENOY                             #";
    cout << "\n#                             =======                            #";
    cout << "\n# Press 1: Eisagwgi stoixeiwn komvou me vasi arithmo tautotitas  #";
    cout << "\n# Press 2: Ektipwsi twn stoixeiwn tou dentroy                    #";
    cout << "\n#          vasi tis endo-diatetagmenis dieleusis                 #";
    cout << "\n# Press 0: Exodos                                                #";
    cout << "\n##################################################################";
    cout << "\nDwste epilogi: ";
    int value=0;
    cin >> value;
    return value;
}