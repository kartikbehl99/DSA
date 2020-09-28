#include <iostream>
#include <cstring>
using namespace std;

int lcs(string s1, string s2, int **memo)
{
    int s1Length = s1.length();
    int s2Length = s2.length();

    if (s1Length == 0 || s2Length == 0)
        return 0;

    int k = 0;
    while (k < s2Length)
    {
        if (s2[k] == s1[0])
            break;
        ++k;
    }

    if (k == s2Length)
    {
        memo[s1Length][s2Length] = lcs(s1.substr(1), s2, memo);
        return memo[s1Length][s2Length];
    }

    memo[s1Length][s2Length] = max(1 + lcs(s1.substr(1), s2.substr(k + 1), memo), lcs(s1.substr(1), s2, memo));
    return memo[s1Length][s2Length];
}

int lcs(string s1, string s2)
{
    int s1Length = s1.length();
    int s2Length = s2.length();
    int **memo = new int *[s1Length + 1];
    for (int i = 0; i <= s1Length; i++)
    {
        memo[i] = new int[s2Length + 1];
        for (int j = 0; j <= s2Length; j++)
        {
            memo[i][j] = -1;
        }
    }

    return lcs(s1, s2, memo);
}

int main()
{
    string s1 = "AC";
    string s2 = "ABC";

    cout << lcs(s1, s2);
}