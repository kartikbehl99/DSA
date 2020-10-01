#include <iostream>
#include <climits>
using namespace std;

int minSubsetDifferenceUtil(int *arr, int n, int sumCurr, int sumTotal, int **memo, int &count)
{
    if (n == 0)
    {
        return abs(abs(sumTotal - sumCurr) - sumCurr);
    }

    if (memo[n][sumCurr] != -1)
        return memo[n][sumCurr];
    count++;
    memo[n][sumCurr] = min(minSubsetDifferenceUtil(arr, n - 1, sumCurr + arr[n - 1], sumTotal, memo, count), minSubsetDifferenceUtil(arr, n - 1, sumCurr, sumTotal, memo, count));
    return memo[n][sumCurr];
}

int minSubsetDifference(int *arr, int n, int &count)
{
    int sumTotal = 0;
    int sumCurr = 0;

    for (int i = 0; i < n; i++)
    {
        sumTotal += arr[i];
    }

    int **memo = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[sumTotal + 1];
        for (int j = 0; j <= sumTotal; j++)
        {
            memo[i][j] = -1;
        }
    }
    return minSubsetDifferenceUtil(arr, n, sumCurr, sumTotal, memo, count);
}

int minSubsetDifferenceBU(int *arr, int n)
{
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];

    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sumTotal + 1];
        for (int j = 0; j <= sumTotal; j++)
        {
            if (i == 0)
                dp[i][j] = sumTotal;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sumTotal; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sumTotal];
}

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7};
    int count = 0;
    cout << minSubsetDifference(arr, n, count) << endl;
    cout << minSubsetDifferenceBU(arr, n);
    // cout << count << endl;
}