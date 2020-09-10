#include <iostream>
#include <array>
using namespace std;

void displayArr(int arr[], int idx)
{
    cout << idx << " " << (sizeof(arr) / sizeof(arr[0])) << endl;
    if (idx == (sizeof(arr) / sizeof(arr[0])))
        return;
    // cout << arr[idx] << endl;
    displayArr(arr, idx + 1);
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
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << sizeof(arr) << endl;
    displayArr(arr, 0);
}