#include <iostream>
#include <climits>
using namespace std;

int cutRod(int *price, int n, int *memo)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return price[n - 1];

    if (memo[n] != -1)
        return memo[n];

    for (int i = n; i >= 1; i--)
    {
        memo[n] = max(memo[n], price[i - 1] + cutRod(price, n - i, memo));
    }

    return memo[n];
}

int cutRod(int *price, int n)
{
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    return cutRod(price, n, memo);
}

int main()
{
    int n = 8;
    int price[n] = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << cutRod(price, n);
}