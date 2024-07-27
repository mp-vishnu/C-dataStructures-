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
            cout << " <-> ";
        }
    }
}
void del(node *&head, int num)
{
    if (head == NULL)
        return;

    node *temp;
    if (head->data == num)
    {
        temp = head;
        head = head->nxt;
        if (head != NULL)
        {
            head->prev = NULL;
        }
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
                if (cur->nxt != NULL)
                {
                    cur->nxt->prev = cur;
                }
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
    head->nxt->prev = head;
    head->nxt->nxt = new node(6);
    head->nxt->nxt->prev = head->nxt;
    display(head);
    int num;
    cout << " Enter data " << endl;
    cin >> num;
    del(head, num);
    display(head);
    return 0;
}
