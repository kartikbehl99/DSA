#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(vector<int> sides)
{
    sort(sides.begin(), sides.end());

    long long height = sides[2] - sides[0];
    long long base = sides[1];

    return ceil(sqrt(pow(height, 2) + pow(base, 2)));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> v(3, 0);
        cin >> v[0] >> v[1] >> v[2];
        cout << solve(v) << "\n";
    }
}