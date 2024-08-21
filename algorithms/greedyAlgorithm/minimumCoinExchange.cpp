#include <iostream>
using namespace std;

#define max 10

int ans[max];

int findMinCoins(int coins[], int size, int value)
{
    int i, count = 0;

    for (i = 0; i < size; i++)
    {
        while (value >= coins[i])
        {
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if (value == 0)
            break;
    }

    return count;
}

int main()
{
    int n = 4;
    int arr[4] = {25, 20, 10, 5};
    int value = 105;

    cout << "Minimum coins required to make the given value : ";
    cout << findMinCoins(arr, n, value) << endl;

    return 0;
}
