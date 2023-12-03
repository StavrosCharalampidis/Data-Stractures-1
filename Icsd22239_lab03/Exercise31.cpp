
#include <iostream>

template <typename T>
class Node {
    private:
        T data;
        Node<T> *Left, *Right;

    public:
        Node(T val){
            this->data = val;
            this->Left = NULL;
            this->Right = NULL;
        };

        Node<T> * insert_node(Node<T> **root, T data) {
            if (*root == NULL) {
                Node<T> *new_node = new Node<T>(data);
                new_node->Left = NULL;
                new_node->Right = NULL;
                return new_node;
            }

            if (data < (*root)->data) {
            (*root)->Left = insert_node(&(*root)->Left, data);
            }
            else {
            (*root)->Right = insert_node(&(*root)->Right, data);
            }
            return *root;
        }

        void inorder(Node<T> *root) {
            if (root == NULL){
                return;
            }
            
            inorder(root->Left);
            printf("%d ", root->data);
            inorder(root->Right);
            
        }

        void printPreOrder(Node<T> *root){
            if (root == NULL){
                return;
            }
            
            printf("%d ", root->data);
            printPreOrder(root->Left);
            printPreOrder(root->Right);
            

        }

        Node<T> * Delete(Node<T> *root, T val) {

            if (root == NULL) {
                std::cout << "Node not found ";
                return NULL;
            }

            if (root->data > val) {
                root->Left = Delete(root->Left, val);
            }

            else if (root->data < val) {
                root->Right = Delete(root->Right, val);
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

                    root->data = temp->data;
                    root->Right = Delete(root->Right, temp->data);
                }
            }

            return root;
        }

};







    

int main(int argc, char const *argv[])
{
    Node<int> *root = new Node<int>(10);
    (*root).insert_node(&root, 20);
    (*root).insert_node(&root, 0);
    (*root).insert_node(&root, 60);
    printf("inorder \n");
    (*root).inorder(root);
    printf("\npreorder \n");
    (*root).printPreOrder(root);
    printf("\n");

    printf("Delete \n");
    (*root).Delete (root, 10);
    printf("inorder \n");
    (*root).inorder(root);

    printf("\npreorder \n");
    (*root).printPreOrder(root);
    printf("\n");
    return 0;
}
