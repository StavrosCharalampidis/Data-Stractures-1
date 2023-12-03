
#include <iostream>

template <typename T>
class Node {
    private:
        T User_ID;
        Node<T> *Left, *Right;

    public:
        Node(T User_ID){
            this->User_ID = User_ID;
            this->Left = NULL;
            this->Right = NULL;
        };

        Node(){
            this->Left = NULL;
            this->Right = NULL;
        };

        Node<T> * insert_node(Node<T> **root, T User_ID) {
            if (*root == NULL) {
                Node<T> *new_node = new Node<T>(User_ID);
                new_node->Left = NULL;
                new_node->Right = NULL;
                return new_node;
            }

            if (User_ID < (*root)->User_ID) {
            (*root)->Left = insert_node(&(*root)->Left, User_ID);
            }
            else {
            (*root)->Right = insert_node(&(*root)->Right, User_ID);
            }
            return *root;
        }

        void inorder(Node<T> *root) {
            if (root == NULL){
                return;
            }
            
            inorder(root->Left);
            printf("%d ", root->User_ID);
            inorder(root->Right);
            
        }

        void printPreOrder(Node<T> *root){
            if (root == NULL){
                return;
            }
            
            printf("%d ", root->User_ID);
            printPreOrder(root->Left);
            printPreOrder(root->Right);
            

        }

        Node<T> * Delete(Node<T> *root, T User_ID) {

            if (root == NULL) {
                std::cout << "Node not found ";
                return NULL;
            }

            if (root->User_ID > User_ID) {
                root->Left = Delete(root->Left, User_ID);
            }

            else if (root->User_ID < User_ID) {
                root->Right = Delete(root->Right, User_ID);
            }

            else {

                if (root->Left == NULL) {
                    Node<T> *temp = root->Right;
                    free(root);
                    return temp;
                }

                else if (root->Right == NULL) {
                    Node<T> *temp = root->Left;
                    free(root);
                    return temp;
                }

                else {
                    Node<T> *temp = root->Right;

                    while (temp->Left != NULL){
                        temp = temp->Left;
                    }

                    root->User_ID = temp->User_ID;
                    root->Right = Delete(root->Right, temp->User_ID);
                }
            }
            return root;
        }

};







    

int main(int argc, char const *argv[]) {
    Node<int> *root = new Node<int>();
    int choice, val;
    std::cout << "Give choice: " << std::endl;
    std::cin >> choice;

    while (choice != 0) {
        
        if (choice == 1) {
            std::cout << "Give data: " << std::endl;
            std::cin >> val;
            (*root).insert_node(&root, val);
        }

        if (choice == 2) {
            printf("\npreorder \n");
            (*root).printPreOrder(root);
        }
        
        

        std::cout << "Give choice: " << std::endl;
        std::cin >> choice;
    }


    // (*root).insert_node(&root, 20);
    // (*root).insert_node(&root, 0);
    // (*root).insert_node(&root, 60);
    // printf("inorder \n");
    // (*root).inorder(root);
    // printf("\npreorder \n");
    // (*root).printPreOrder(root);
    // printf("\n");

    // printf("Delete \n");
    // (*root).Delete (root, 10);
    // printf("inorder \n");
    // (*root).inorder(root);

    // printf("\npreorder \n");
    // (*root).printPreOrder(root);
    // printf("\n");
    return 0;
}
