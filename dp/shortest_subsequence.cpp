#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int solve(string S, string V, int **memo)
{
    if (S.length() == 0)
        return INT_MAX - 1;
    if (V.length() == 0)
        return 1;

    int sLength = S.length();
    int vLength = V.length();
    if (memo[sLength][vLength] != -1)
    {
        return memo[sLength][vLength];
    }

    int k = 0;

    while (k < vLength)
    {
        if (V[k] == S[0])
            break;
        ++k;
    }

    if (k == vLength)
        return 1;

    memo[sLength][vLength] = min(1 + solve(S.substr(1), V.substr(k + 1)), solve(S.substr(1), V));
    return memo[sLength][vLength];
}

int solve(string S, string V)
{
    int sLength = S.length();
    int vLength = V.length();

    int **memo = new int *[sLength + 1];

    for (int i = 0; i <= sLength; i++)
    {
        memo[i] = new int[vLength + 1];

        for (int j = 0; j <= vLength; j++)
        {
            memo[i][j] = -1;
        }
    }
    return solve(S, V, memo);
}