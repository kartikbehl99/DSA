#include <iostream>
using namespace std;

int *solve(int *arr1, int *arr2, int n1, int n2)
{
    int *arr3 = new int[max(n1, n2) + 1];

    int e1 = n1 - 1;
    int e2 = n2 - 1;
    int e3 = max(n1, n2);
    int carry = 0;

    while (e1 >= 0 && e2 >= 0)
    {
        int sum = arr1[e1--] + arr2[e2--] + carry;
        carry = sum / 10;
        sum %= 10;
        arr3[e3--] = sum;
    }

    while (e1 >= 0)
    {
        int sum = arr1[e1--] + carry;
        carry = sum / 10;
        sum %= 10;
        arr3[e3--] = sum;
    }

    while (e2 >= 0)
    {
        int sum = arr2[e2--] + carry;
        carry = sum / 10;
        sum %= 10;
        arr3[e3--] = sum;
    }

    arr3[e3] = carry;

    return arr3;
}

int main()
{
    int n1;
    int n2;

    cin >> n1;
    int arr1[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cin >> n2;
    int arr2[n2];

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
}