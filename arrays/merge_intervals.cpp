#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isOverlapping(vector<int> interval1, vector<int> interval2)
{
    return interval1[1] >= interval2[0];
}

vector<vector<int>> merge(vector<vector<int>> intervals, int n)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> mergedIntevals;

    int s = 0;
    int nxt = s + 1;

    while (nxt < n)
    {
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        int i1, i2;
        cin >> i1 >> i2;
        v.push_back({i1, i2});
    }
}