#include <iostream>
using namespace std;
struct node
{
    int data;
    node *nxt;
    node *prev;
    node(int val)
    {
        data = val;
        nxt = NULL;
        prev = NULL;
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
            cout << " = ";
        }
    }
}

void insert(node *&head, int num)
{
    node *temp = new node(num);
    if (head == NULL)
        return;
    else
    {
        temp->nxt = head;
        head->prev = temp;
        head = temp;
    }
}

int main()
{
    node *head = new node(5);
    head->nxt = new node(3);
    head->nxt->prev = head;
    head->nxt->nxt = new node(6);
    head->nxt->nxt->prev = head->nxt;
    display(head);
    int num;
    cout << " Enter data " << endl;
    cin >> num;
    insert(head, num);
    display(head);
    return 0;
}
