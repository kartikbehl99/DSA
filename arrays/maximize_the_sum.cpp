#include <iostream>
#include <vector>
using namespace std;

int *inputArr(int n)
{
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    return arr;
}

long maxPathSum(int *arr1, int n1, int *arr2, int n2)
{
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;

    int s1 = 0;
    int s2 = 0;

    while (s1 < n1 && s2 < n2)
    {
        if (arr1[s1] < arr2[s2])
        {
            sum1 += arr1[s1];
            s1++;
        }
        else if (arr2[s2] < arr1[s1])
        {
            sum2 += arr2[s2];
            s2++;
        }
        else
        {
            sum1 += arr1[s1++];
            sum2 += arr2[s2++];
            sum += max(sum1, sum2);
            sum1 = sum2 = 0;
        }
    }

    while (s1 < n1)
        sum1 += arr1[s1++];

    while (s2 < n2)
        sum2 += arr2[s2++];

    sum += max(sum1, sum2);

    return sum;
}

int main()
{
    int n1, n2;
    cin >> n1;
    int *arr1 = inputArr(n1);
    cin >> n2;
    int *arr2 = inputArr(n2);

    cout << maxPathSum(arr1, n1, arr2, n2);
}