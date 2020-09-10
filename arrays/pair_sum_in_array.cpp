#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void pairSum(int *arr, int n, int x)
{
    unordered_map<int, int> m;
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        ++m[arr[i]];
    }

    for (int i = 0; i < n; i++)
    {
        if (m[x - arr[i]])
        {
            --m[arr[i]];
            int j = 0;
            while (j < m[x - arr[i]])
            {
                cout << min(arr[i], x - arr[i]) << " " << max(arr[i], x - arr[i]) << "\n";
                j++;
            }
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

    int x;
    cin >> x;

    pairSum(arr, n, x);
}