#include <iostream>
using namespace std;

int searchNumber(int arr[], int num)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    cout << "Hello !!!" << std::endl;
    int num, f = -1;
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Original array" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter no" << endl;
    cin >> num;

    f = searchNumber(arr, num);
    if (f != -1)
    {
        cout << endl
             << num << " found at " << f + 1;
    }
    else
    {
        cout << endl
             << " not found";
    }
    return 0;
}
