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
    return 0;
}