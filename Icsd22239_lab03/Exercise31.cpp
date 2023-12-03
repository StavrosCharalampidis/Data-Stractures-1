
#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *Left, *Right;

public:
    Node(T val) : data(val), Left(NULL), Right(NULL) {};
    Node<T> * insert_node(Node<T> **root, T data)
    {
        if (*root == NULL)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->Left = NULL;
            new_node->Right = NULL;
            return new_node;
        }
        if (data < (*root)->data)
        {
            (*root)->Left = insert_node(&(*root)->Left, data);
        }
        else
        {
            (*root)->Right = insert_node(&(*root)->Right, data);
        }

        return *root;
    };

    void inorder(Node<T> *root)
    {
        if (root != NULL)
        {
            inorder(root->Left);
            printf("%d ", root->data);
            inorder(root->Right);
        }
    };

    void printPreOrder(Node<T> *root){
        if (root != NULL){
            printf("%d ", root->data);
            printPreOrder(root->Left);
            printPreOrder(root->Right);
        }

    };

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
    return 0;
}
