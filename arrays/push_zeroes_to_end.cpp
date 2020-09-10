#include <iostream>
using namespace std;

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solve(int *input, int n)
{
    int nonZero = 0;

    for (int i = 0; i < n; i++)
    {
        if (input[i] != 0)
        {
            swap(input[i], input[nonZero]);
            nonZero++;
        }
    }
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

    solve(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}