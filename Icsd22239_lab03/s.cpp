Tree *Delete(Tree *root, int x) {

    if (root == NULL) {
        cout << "Node not found ";
        return NULL;
    }

    if (root->data > x) {
        root->left = Delete(root->left, x);
    }

    else if (root->data < x) {
        root->right = Delete(root->right, x);
    }
    else {

        if (root->left == NULL) {
            Tree *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        else {

            Tree *temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;

            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}