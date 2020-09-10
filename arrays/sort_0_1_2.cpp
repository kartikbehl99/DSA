#include <iostream>
using namespace std;

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solve(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    int nxt = s + 1;

    while (s < e && nxt < e)
    {
        if (s >= nxt)
            nxt++;
        else if (arr[s] == 0)
            s++;
        else if (arr[e] == 2)
            e--;
        else
        {
            if (arr[s] == 2)
            {
                swap(arr[s], arr[e]);
                e--;
            }
            else if (arr[e] == 0)
            {
                swap(arr[s], arr[e]);
                s++;
            }

            else if (arr[nxt] == 0)
            {
                swap(arr[nxt], arr[s]);
                s++;
                nxt++;
            }
            else if (arr[nxt] == 2)
            {
                swap(arr[nxt], arr[e]);
                e--;
            }
            else
            {
                nxt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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