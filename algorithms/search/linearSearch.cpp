#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    int i;

    for (i = 0; i < size; i++)
        if (arr[i] == key)
            return 1;

    return 0;
}

int main()
{
    int arr[5] = {86, 91, 34, 50, 0};

    int key = 50;
    if (linearSearch(arr, 5, key) == 1)
        cout << "key - 50 : Search Found\n";
    else
        cout << "Key - 50 : Search Not Found\n";

    key = 5;
    if (linearSearch(arr, 5, key) == 1)
        cout << "key - 5 : Search Found\n";
    else
        cout << "Key - 5 : Search Not Found\n";
}
