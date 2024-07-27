#include <iostream>
using namespace std;
struct node
{
    int data;
    node *nxt;
    node(int val)
    {
        data = val;
        nxt = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->nxt;
        if (temp != NULL)
        {
            cout << "->";
        }
    }
}

bool search(node *head, int num)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
            return true;
        temp = temp->nxt;
    }
    return false;
}

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->nxt = new node(6);
    display(head);
    int num;
    cout << " Enter data " << endl;
    cin >> num;
    bool f = search(head, num);
    if (f)
        cout << " found ";
    else
        cout << "not found";
    return 0;
}
