#include <iostream>
using namespace std;

bool isSubsetSum(int *arr, int n, int sum, int **memo)
{
    if (sum == 0)
        return true;
    if (n == 0 || sum < 0)
        return false;

    if (memo[n][sum] != -1)
        return memo[n];

    memo[n][sum] = isSubsetSum(arr, n - 1, sum - arr[n - 1], memo) || isSubsetSum(arr, n - 1, sum, memo);
    return memo[n][sum];
}

bool isSubsetSum(int *arr, int n, int sum)
{
    int **memo = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        memo[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            memo[i][j] = -1;
        }
    }

    return isSubsetSum(arr, n, sum, memo);
}

int main()
{
    int arr[4] = {3, 4, 5, 2};
    int sum = 1;

    cout << isSubsetSum(arr, 4, sum);
}