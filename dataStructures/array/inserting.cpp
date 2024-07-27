#include <iostream>
using namespace std;

void insertNumber(int arr[], int &size, int num, int index)
{
    for (int i = size; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = num;
    ++size;
}
int main()
{
    cout << "Hello !!!" << std::endl;
    int msize = 10;
    // int arr[msize]={1,2,3,4,5};   --->cannot initialize an array with a size that is determined at runtime using a variable
    int *arr = new int[msize];
    int num, index, size = 5;
    for (int i = 0; i < msize; ++i)
    {
        arr[i] = i + 1;
    }
    cout << "Original array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter no: & position ";
    cin >> num;
    cin >> index;

    insertNumber(arr, size, num, index);

    cout << "Array after inserting" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
