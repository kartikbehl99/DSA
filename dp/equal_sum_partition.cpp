#include <iostream>
using namespace std;

bool equalPartition(int *arr, int n, int arrSum, int **memo)
{
    if (arrSum == 0)
        return true;
    if (n == 0 || arrSum < 0)
        return false;

    if (memo[n][arrSum] != -1)
    {
        return memo[n][arrSum];
    }

    memo[n][arrSum] = equalPartition(arr, n - 1, arrSum - arr[n - 1], memo) || equalPartition(arr, n - 1, arrSum, memo);

    return memo[n][arrSum];
}

bool equalPartition(int *arr, int n, int arrSum)
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

    return equalPartition(arr, n, arrSum, memo);
}

int main()
{
    int arr[4] = {1, 5, 10, 5};
    int arrSum = 0;

    for (int i = 0; i < 4; i++)
    {
        arrSum += arr[i];
    }

    cout << equalPartition(arr, 4, arrSum / 2);
}