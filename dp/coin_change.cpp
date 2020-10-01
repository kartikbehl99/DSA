#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int n, int value, int **memo)
{
    if (value == 0)
        return 1;
    if (value < 0)
        return 0;
    if (n <= 0 && value > 0)
        return 0;

    if (memo[n][value] != -1)
    {
        return memo[n][value];
    }

    memo[n][value] = countWaysToMakeChange(denominations, n - 1, value, memo) + countWaysToMakeChange(denominations, n, value - denominations[n - 1], memo);
    return memo[n][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **memo = new int *[numDenominations + 1];

    for (int i = 0; i <= numDenominations; i++)
    {
        memo[i] = new int[value + 1];
    }

    for (int i = 0; i <= numDenominations; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            memo[i][j] = -1;
        }
    }

    return countWaysToMakeChange(denominations, numDenominations, value, memo);
}

int countWaysToMakeChangeBU(int denominations[], int numDenominations, int value)
{
    int **dp = new int *[numDenominations + 1];
    for (int i = 0; i <= numDenominations; i++)
    {
        dp[i] = new int[value + 1];
        for (int j = 0; j <= value; j++)
        {
            if (j == 0 && i != 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= numDenominations; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            if (denominations[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - denominations[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[numDenominations][value];
}

int main()
{
    int denomination[4] = {2, 5, 3, 6};
    int value = 10;

    cout << countWaysToMakeChangeBU(denomination, 4, value);
}