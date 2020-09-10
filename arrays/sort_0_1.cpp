#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortZeroOne(int *arr, int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        if (arr[s] == 0)
            s++;
        else if (arr[s] == 1 && arr[e] == 0)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else if (arr[e] == 1)
            e--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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

    sortZeroOne(arr, n);
}