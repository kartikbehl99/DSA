int getMinSteps(int n, int *memo)
{
    if (n == 0 || n == 1)
    {
        memo[n] = 0;
        return 0;
    }

    if (memo[n] != INT_MAX)
    {
        return memo[n];
    }

    if (n % 2 == 0 && n % 3 == 0)
    {
        memo[n] = 1 + min(getMinSteps(n - 1, memo), min(getMinSteps(n / 2, memo), getMinSteps(n / 3, memo)));
    }
    else if (n % 3 == 0)
    {
        memo[n] = 1 + min(getMinSteps(n - 1, memo), getMinSteps(n / 3, memo));
    }
    else if (n % 2 == 0)
    {
        memo[n] = 1 + min(getMinSteps(n - 1, memo), getMinSteps(n / 2, memo));
    }
    else
    {
        memo[n] = 1 + getMinSteps(n - 1, memo);
    }

    return memo[n];
}

int countStepsToOne(int n)
{
    int *memo = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = INT_MAX;
    }

    return getMinSteps(n, memo);
}
