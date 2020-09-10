#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getPascalTriangle(int n)
{
    vector<vector<int>> pt;

    for (int i = 1; i <= n; i++)
    {
        vector<int> row(i, 1);
        for (int j = 1; j <= i; j++)
        {
            if (i == 1 || i == 2)
            {
                row[j - 1] = 1;
            }
            else
            {
                if (j == 1 || j == n)
                    continue;
                row[j - 1] = pt[i - 2][j - 1] + pt[i - 2][j - 2];
            }
        }
        pt.push_back(row);
    }

    return pt;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> pt = getPascalTriangle(n);

    for (vector<int> row : pt)
    {
        for (int i : row)
            cout << i << " ";
        cout << "\n";
    }
}