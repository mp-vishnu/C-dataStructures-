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
    if (head == NULL)
        return;

    node *temp = head;
    do
    {
        cout << temp->data;
        temp = temp->nxt;
        if (temp != head)
        {
            cout << " -> ";
        }
    } while (temp != head);
    cout << endl;
}

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->nxt = new node(6);
    head->nxt->nxt->nxt = head; // Making the list circular by pointing the last node to head

    display(head);

    return 0;
}
