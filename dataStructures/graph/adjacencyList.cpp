#include <iostream>
using namespace std;

#define V 5

class Node
{
public:
    int data;
    Node *next;
};

class AdjList
{
    Node *adjList[V];

public:
    AdjList()
    {
        int i;

        for (i = 0; i < V; i++)
            adjList[i] = NULL;
    }

    int hasEdge(int src, int dest)
    {
        Node *temp = adjList[src];

        while (temp != NULL)
        {
            if (temp->data == dest)
                return 1;
            temp = temp->next;
        }

        return 0;
    }

    void removeEdge(int src, int dest)
    {
        if (adjList[src] == NULL)
            return;

        if (adjList[src]->data == dest)
        {
            Node *temp = adjList[src];
            adjList[src] = adjList[src]->next;
            delete temp;
        }
        else
        {
            Node *current = adjList[src], *temp;

            while (current->next != NULL)
            {
                if (current->next->data == dest)
                {
                    temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    break;
                }
                else
                    current = current->next;
            }
        }
    }

    void addEdge(int src, int dest)
    {
        Node *newNode = new Node();
        newNode->data = dest;
        newNode->next = NULL;

        if (adjList[src] == NULL)
            adjList[src] = newNode;
        else
        {
            Node *last = adjList[src];

            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
        }
    }

    void printGraph()
    {
        int i;

        for (i = 0; i < V; i++)
        {
            Node *temp = adjList[i];

            cout << "adjList[" << i << "]->";

            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    AdjList obj;

    cout << "Adding Edge From 0 to 1" << endl;
    obj.addEdge(0, 1);
    cout << "Adding Edge From 0 to 2" << endl;
    obj.addEdge(0, 2);
    cout << "Adding Edge From 0 to 3" << endl;
    obj.addEdge(0, 3);
    cout << "Adding Edge From 1 to 3" << endl;
    obj.addEdge(1, 3);
    cout << "Adding Edge From 1 to 4" << endl;
    obj.addEdge(1, 4);
    cout << "Adding Edge From 2 to 3" << endl;
    obj.addEdge(2, 3);
    cout << "Adding Edge From 3 to 4" << endl;
    obj.addEdge(3, 4);

    cout << "Adjacency List Representation of the Graph" << endl;
    obj.printGraph();

    cout << "Removing Edge(0, 2).." << endl;
    obj.removeEdge(0, 2);

    cout << "Adjacency List Representation of the Graph" << endl;
    obj.printGraph();

    cout << "(0,1) has Edge?" << endl;
    if (obj.hasEdge(0, 1) == 1)
        cout << "Edge Found" << endl;
    else
        cout << "Edge Not Found" << endl;

    cout << "(0,2) has Edge?" << endl;
    if (obj.hasEdge(0, 2) == 1)
        cout << "Edge Found" << endl;
    else
        cout << "Edge Not Found" << endl;

    return 0;
}
