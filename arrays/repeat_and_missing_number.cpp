#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

void solve(int *arr, int n)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!m.count(i))
        {
            cout << "Missing: " << i << "\n";
        }
        else if (m[i] > 1)
        {
            cout << "Repeating: " << i << "\n";
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(arr, n);
}