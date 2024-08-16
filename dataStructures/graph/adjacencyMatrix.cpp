#include <iostream>
using namespace std;

#define V 5

class AdjMatrix
{
    int arr[V][V];

public:
    // Initialize the adjacency matrix in the constructor.
    AdjMatrix()
    {
        int i, j;

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                arr[i][j] = 0;
    }

    void addEdge(int src, int dest)
    {
        arr[src][dest] = 1;
    }

    void printAdjMatrix()
    {
        int i, j;

        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int hasEdge(int src, int dest)
    {
        if (arr[src][dest] == 1)
            return 1;

        return 0;
    }

    void removeEdge(int src, int dest)
    {
        arr[src][dest] = 0;
    }
};

int main()
{
    AdjMatrix obj;

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

    cout << "Adjacency Matrix Representation of the Graph" << endl;
    obj.printAdjMatrix();

    cout << "Removing Edge(0, 2).." << endl;
    obj.removeEdge(0, 2);

    cout << "Adjacency Matrix Representation of the Graph" << endl;
    obj.printAdjMatrix();

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
