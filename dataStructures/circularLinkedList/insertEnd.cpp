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

void insertAtEnd(node *&head, int num)
{
    node *newNode = new node(num);
    if (head == NULL)
    {
        head = newNode;
        head->nxt = head;
    }
    else
    {
        node *temp = head;
        while (temp->nxt != head)
        {
            temp = temp->nxt;
        }
        temp->nxt = newNode;
        newNode->nxt = head;
    }
}

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->nxt = new node(6);
    head->nxt->nxt->nxt = head; // Making the list circular by pointing the last node to head

    display(head);

    int num;
    cout << "Enter data to insert at the end: ";
    cin >> num;

    insertAtEnd(head, num);
    display(head);

    return 0;
}
