#include <iostream>
using namespace std;

int getCount(int *arr, int n, int X, int **memo)
{
    if (X == 0)
        return 1;
    if (n <= 0 || X < 0)
        return 0;

    if (memo[n][X] != -1)
        return memo[n][X];

    memo[n][X] = getCount(arr, n - 1, X - arr[n - 1], memo) + getCount(arr, n - 1, X, memo);
    return memo[n][X];
}

int getCount(int *arr, int n, int X)
{
    int **memo = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[X + 1];
        for (int j = 0; j <= X; j++)
        {
            memo[i][j] = -1;
        }
    }

    return getCount(arr, n, X, memo);
}

int getCountBU(int *arr, int n, int X)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[X + 1];
        for (int j = 0; j <= X; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][X];
}

int main()
{
    int n = 4;
    int arr[n] = {1, 2, 3, 3};
    int X = 6;
    cout << getCountBU(arr, n, X);
}