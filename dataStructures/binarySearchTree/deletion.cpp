// bst insertion...
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int getRightMin(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

node *removeNode(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > val)
    {
        root->left = removeNode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = removeNode(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right, rightMin);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert(root, 10);
    insert(root, 7);
    insert(root, 12);
    insert(root, 4);
    insert(root, 5);
    insert(root, 2);
    insert(root, 3);
    inorder(root);
    removeNode(root, 12);
    inorder(root);
    return 0;
}