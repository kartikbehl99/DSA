#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2, int **memo, int i, int j)
{
    if (s1 == s2)
    {
        return 0;
    }

    if (s1.length() == 0)
    {
        return s2.length();
    }

    if (s2.length() == 0)
    {
        return s1.length();
    }

    if (memo[i][j] != -1)
    {
        return 1 + memo[i][j];
    }

    if (s1[0] == s2[0])
    {
        memo[i][j] = editDistance(s1.substr(1), s2.substr(1), memo, i + 1, j + 1);
        return memo[i][j];
    }
    memo[i][j] = 1 + min(editDistance(s1, s2.substr(1), memo, i, j + 1), min(editDistance(s1.substr(1), s2, memo, i + 1, j), editDistance(s1.substr(1), s2.substr(1), memo, i + 1, j + 1)));
    return memo[i][j];
}

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **memo = new int *[m];

    for (int i = 0; i < m; i++)
    {
        memo[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = -1;
        }
    }

    return editDistance(s1, s2, memo, 0, 0);
}