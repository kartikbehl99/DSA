#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isGreater(vector<int> v, vector<int> nxt, int size)
{
    for (int i = size - 1; i >= 0; i++)
    {
        if (v[i] < nxt[i])
            return true;
    }
    return false;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> nextGreater(vector<int> v)
{
    int size = v.size();

    for (int i = size - 1; i >= 1; i--)
    {
        vector<int> temp = v;
        swap(temp[i], temp[i - 1]);
        if (isGreater(v, temp, size))
            return temp;
    }

    sort(v.begin(), v.end());
    return v;
}