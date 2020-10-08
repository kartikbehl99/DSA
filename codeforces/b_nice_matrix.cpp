#include <bits/stdc++.h>
using namespace std;

long long solve(vector<vector<int>> v, int n, int m, long long sum)
{
    long long avg = floor(float(sum) / float(m * n));
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count += abs(v[i][j] - avg);
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n, vector<int>(m, 0));

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                sum += v[i][j];
            }
        }

        cout << solve(v, n, m, sum) << "\n";
    }
}