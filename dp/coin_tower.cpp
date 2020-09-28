#include <iostream>
using namespace std;

bool solve(int n, int x, int y, int *memo)
{
    if (n < 0)
        return false;
    if (n - 1 == 0 | n - x == 0 || n - y == 0)
        return true;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = !solve(n - 1, x, y, memo) || !solve(n - x, x, y, memo) || !solve(n - y, x, y, memo);
    return memo[n];
}

string solve(int n, int x, int y)
{
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    if (solve(n, x, y, memo))
    {
        return "Beerus";
    }
    return "Whis";
}