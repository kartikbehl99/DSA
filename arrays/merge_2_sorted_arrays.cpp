#include <iostream>
#include <algorithm>

using namespace std;

int getIndex(int *arr, int n, int ele)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] < ele && mid < e && arr[mid + 1] > ele)
        {
            return mid + 1;
        }
        else if (arr[mid] > ele)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void merge(int *arr1, int m, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = getIndex(arr1, m, arr2[i]);
        if (index != -1)
            swap(arr1[index], arr2[i]);
    }

    sort(arr2, arr2 + n);

    for (int i = 0; i < m; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int m, n;
    cin >> m >> n;

    int arr1[m], arr2[n];

    for (int i = 0; i < m; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    merge(arr1, m, arr2, n);
}