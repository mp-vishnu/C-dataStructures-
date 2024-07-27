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
            cout << "->";
        }
    } while (temp != head);
    cout << endl;
}

bool search(node *head, int num)
{
    if (head == NULL)
        return false;
    node *temp = head;
    do
    {
        if (temp->data == num)
        {
            return true;
        }
        temp = temp->nxt;
    } while (temp != head);
    return false;
}

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->nxt = new node(6);
    head->nxt->nxt->nxt = head; // Making the list circular by pointing the last node to head

    display(head);

    int num;
    cout << "Enter data to search: ";
    cin >> num;
    bool found = search(head, num);
    if (found)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
