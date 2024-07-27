#include <iostream>
using namespace std;

int findIndex(int arr[], int num, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
void removeElement(int arr[], int loc, int &size)
{
    for (int i = loc; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
}
int main()
{
    cout << "Hello !!!" << std::endl;
    int num, loc, size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Original array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter no ";
    cin >> num;

    loc = findIndex(arr, num, size);
    if (loc != -1)
        removeElement(arr, loc, size);
    else
        cout << endl
             << " Element not found" << endl;

    cout << "Array after removing" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
