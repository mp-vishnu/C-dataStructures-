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

void del(node *&head, int num)
{
    node *temp;
    if (head->data == num)
    {
        temp = head;
        head = head->nxt;
        delete temp;
    }
    else
    {
        node *cur = head;
        while (cur->nxt != NULL)
        {
            if (cur->nxt->data == num)
            {
                temp = cur->nxt;
                cur->nxt = cur->nxt->nxt;
                delete temp;
                break;
            }
            cur = cur->nxt;
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
    del(head, num);
    display(head);
    return 0;
}
