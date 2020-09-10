#include <iostream>
#define MAX_SIZE 100000
using namespace std;

void printSpiral(int arr[][MAX_SIZE], int m, int n)
{
    int r1 = 0;
    int r2 = m - 1;
    int c1 = 0;
    int c2 = n - 1;

    while (r1 < r2 && c1 < c2)
    {
        for (int i = c1; i <= c2; i++)
        {
            cout << arr[r1][i] << " ";
        }
        ++r1;
        for (int i = r1; i <= r2; i++)
        {
            cout << arr[i][c2] << " ";
        }
        --c2;
        for (int i = c2; i >= c1; i--)
        {
            cout << arr[r2][i] << " ";
        }
        --r2;
        for (int i = r2; i >= r1; i--)
        {
            cout << arr[i][c1] << " ";
        }
        ++c1;
    }
    cout << "\n";
}

int main()
{
    int m, n;
    cin >> m >> n;

    int arr[m][MAX_SIZE];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    printSpiral(arr, m, n);
}