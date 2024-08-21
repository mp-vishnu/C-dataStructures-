#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}

int main()
{
    int arr[8] = {10, 23, 45, 70, 90, 100, 111, 123};

    int key = 45;
    if (binarySearch(arr, 0, 7, key) == 1)
        cout << "key - 45 : Search Found\n";
    else
        cout << "key - 45 : Search Not Found\n";

    key = 5;
    if (binarySearch(arr, 0, 7, key) == 1)
        cout << "key - 5 : Search Found\n";
    else
        cout << "key - 5 : Search Not Found\n";

    return 0;
}