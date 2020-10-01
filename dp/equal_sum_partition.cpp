#include <iostream>
using namespace std;

bool equalPartition(int *arr, int n, int arrSum, int currSum, int **memo)
{
    if (arrSum == currSum)
        return true;
    if (n == 0 || arrSum < 0)
        return false;

    if (memo[n][arrSum] != -1)
    {
        return memo[n][arrSum];
    }

    memo[n][arrSum] = equalPartition(arr, n - 1, arrSum - arr[n - 1], currSum + arr[n - 1], memo) || equalPartition(arr, n - 1, currSum, arrSum, memo);

    return memo[n][arrSum];
}

bool equalPartition(int *arr, int n, int arrSum, int currSum)
{
    int **memo = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[arrSum + 1];

        for (int j = 0; j <= arrSum; j++)
        {
            memo[i][j] = -1;
        }
    }

    return equalPartition(arr, n, arrSum, currSum, memo);
}

bool equalPartitionBU(int *arr, int n, int arrSum)
{
    if (arrSum % 2 != 0)
        return false;

    arrSum /= 2;
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[arrSum + 1];
        for (int j = 0; j <= arrSum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= arrSum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][arrSum];
}

int main()
{
    int arr[4] = {1, 5, 11, 5};
    int arrSum = 0;
    int currSum = 0;

    for (int i = 0; i < 4; i++)
    {
        arrSum += arr[i];
    }

    cout << equalPartitionBU(arr, 4, arrSum);
}