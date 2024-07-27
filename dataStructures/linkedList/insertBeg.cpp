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

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->nxt = new node(6);
    display(head);
    int num;
    cout << " Enter data " << endl;
    cin >> num;
    node *temp = new node(num);
    temp->nxt = head;
    head = temp;
    display(head);
    return 0;
}
