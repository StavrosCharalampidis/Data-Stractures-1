
#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *Left, *Right;

public:
    Node(T val) : data(val), Left(nullptr), Right(nullptr) {}

    Node<T> * insert_node(Node<T> *root, T data)
    {
        if (root == nullptr)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->Left = nullptr;
            new_node->Right = nullptr;
            return new_node;
        }
        if (data < root->data)
        {
            root->Left = insert_node(root->Left, data);
        }
        else
        {
            root->Right = insert_node(root->Right, data);
        }

        return root;
    }

    void inorder(Node<T> *root)
    {
        if (root != nullptr)
        {
            inorder(root->Left);
            printf("%d ", root->data);
            inorder(root->Right);
        }
    }

};







    

int main(int argc, char const *argv[])
{
    Node<int> *root = new Node<int>(60);
    (*root).insert_node(root, 20);
    (*root).insert_node(root, 50);
    (*root).insert_node(root, 60);
    (*root).inorder(root);
    
    return 0;
}
