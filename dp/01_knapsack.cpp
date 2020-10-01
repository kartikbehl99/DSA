#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight, int **memo)
{
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }

    if (memo[n][maxWeight] != -1)
    {
        return memo[n][maxWeight];
    }

    if (weights[n - 1] <= maxWeight)
    {
        memo[n][maxWeight] = max(values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1], memo), knapsack(weights, values, n - 1, maxWeight, memo));
        return memo[n][maxWeight];
    }

    memo[n][maxWeight] = knapsack(weights, values, n - 1, maxWeight, memo);
    return memo[n][maxWeight];
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **memo = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[maxWeight + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            memo[i][j] = -1;
        }
    }

    return knapsack(weights, values, n, maxWeight, memo);
}

int knapsackBU(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][maxWeight];
}

int main()
{
    int weights[3] = {1, 2, 3};
    int values[3] = {10, 15, 40};
    int maxWeight = 6;
    cout << knapsackBU(weights, values, 3, maxWeight);
}