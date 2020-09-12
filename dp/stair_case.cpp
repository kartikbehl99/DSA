long getAllWays(int n, long *memo)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
    {
        memo[n] = 1;
        return 1;
    }
    if (n == 2)
    {
        memo[n] = 2;
        return 2;
    }
    if (n == 3)
    {
        memo[n] = 4;
        return 4;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    long result = getAllWays(n - 1, memo) + getAllWays(n - 2, memo) + getAllWays(n - 3, memo);
    memo[n] = result;
    return result;
}

long staircase(int n)
{
    long *memo = new long[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    return getAllWays(n, memo);
}
