#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int helper(int **input, int i, int j, int m, int n, int **memo)
{
    if (i >= m || j >= n)
        return INT_MAX;
    if (i == m - 1 && j == n - 1)
    {
        memo[i][j] = input[i][j];
        return memo[i][j];
    }

    if (memo[i][j] != INT_MAX)
    {
        return memo[i][j];
    }

    int sum = min(helper(input, i + 1, j, m, n, memo), min(helper(input, i, j + 1, m, n, memo), helper(input, i + 1, j + 1, m, n, memo)));
    memo[i][j] = sum + input[i][j];

    return memo[i][j];
}

int minCostPath(int **input, int m, int n)
{
    int **memo = new int *[m];

    for (int i = 0; i < n; i++)
    {
        memo[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = INT_MAX;
        }
    }
    return helper(input, 0, 0, m, n, memo);
}