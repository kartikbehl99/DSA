#include <iostream>
using namespace std;

int lis(int *arr, int index, int n, int **memo)
{
    if (n <= 0 || index > n)
        return 0;
    if (n == 1)
        return 1;

    if (memo[index][n] != -1)
        return memo[index][n];

    int i;
    for (i = index + 1; i < n; i++)
    {
        if (arr[i] > arr[index])
            break;
    }

    if (i == n)
    {
        memo[index][n] = lis(arr, index + 1, n - 1, memo);
        return memo[index][n];
    }

    memo[index][n] = max(1 + lis(arr, index + i, n - i, memo), lis(arr, index + 1, n - 1, memo));
    return memo[index][n];
}

int lis(int *arr, int n)
{
    int **memo = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
            memo[i][j] = -1;
    }
    return lis(arr, 0, n, memo);
}

int main()
{
    int n = 6;
    int arr[n] = {50, 3, 10, 7, 40, 80};

    cout << lis(arr, n);
}