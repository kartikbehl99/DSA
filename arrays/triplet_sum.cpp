#include <iostream>
#include <algorithm>

using namespace std;

int *inputArr(int n)
{
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return arr;
}

void printInIncreasingOrder(int n1, int n2, int n3)
{
    if (n1 <= n2 && n2 <= n3)
        cout << n1 << " " << n2 << " " << n3 << "\n";
    else if (n2 <= n1 && n1 <= n3)
        cout << n2 << " " << n1 << " " << n3 << "\n";
    else if (n1 <= n3 && n3 <= n2)
        cout << n1 << " " << n3 << " " << n2 << "\n";
    else if (n2 <= n3 && n3 <= n1)
        cout << n2 << " " << n3 << " " << n1 << "\n";
    else if (n3 <= n1 && n1 <= n2)
        cout << n3 << " " << n1 << " " << n2 << "\n";
    else if (n3 <= n2 && n2 <= n1)
        cout << n3 << " " << n2 << " " << n1 << "\n";
}

void FindTriplet(int *arr, int n, int x)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum > x)
                r--;
            else if (sum < x)
                l++;
            else
            {
                printInIncreasingOrder(arr[i], arr[l], arr[r]);
                l++;
                r--;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = inputArr(n);
    int x;
    cin >> x;

    FindTriplet(arr, n, x);
}