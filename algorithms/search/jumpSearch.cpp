#include <iostream>
using namespace std;

int jumpSearch(int arr[], int size, int key)
{
    int i, start = 0, end = sqrt(size);

    if (key > arr[size - 1] || key < arr[0])
        return 0;
    while (arr[end] < key && start < size)
    {
        start = end;
        end += sqrt(size);
        if (end > size - 1)
            end = size - 1;
    }

    for (i = start; i <= end; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return 0;
}

int main()
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int key = 12;
    if (jumpSearch(arr, 12, key) == 1)
        cout << "key - 12 : Search Found\n";
    else
        cout << "Key - 12 : Search Not Found\n";

    key = 15;
    if (jumpSearch(arr, 12, key) == 1)
        cout << "key - 15 : Search Found\n";
    else
        cout << "Key - 15 : Search Not Found\n";
}
