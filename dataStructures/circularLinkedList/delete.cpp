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

void deleteNode(node *&head, int num)
{
    if (head == NULL)
        return;

    node *temp = head;
    node *prev = NULL;

    // Handle the case where the node to be deleted is the head node
    if (head->data == num)
    {
        if (head->nxt == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            prev = head;
            while (prev->nxt != head)
            {
                prev = prev->nxt;
            }
            node *toDelete = head;
            head = head->nxt;
            prev->nxt = head;
            delete toDelete;
        }
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->nxt != head && temp->data != num)
    {
        prev = temp;
        temp = temp->nxt;
    }

    // If the node is found
    if (temp->data == num)
    {
        prev->nxt = temp->nxt;
        delete temp;
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
    cout << "Enter data to delete: ";
    cin >> num;

    deleteNode(head, num);
    display(head);

    return 0;
}
