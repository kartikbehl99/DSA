#include <iostream>
using namespace std;

int findUnique(int arr[], int n)
{
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        unique ^= arr[i];
    }
    return unique;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findUnique(arr, n);
}