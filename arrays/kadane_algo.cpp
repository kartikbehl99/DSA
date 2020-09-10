#include <iostream>
#include <climits>
using namespace std;

long getMaxSumArraySumDP(int *arr, int n)
{
    long maxSUM = LONG_MIN;
    long sum = LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = max(sum + arr[i], long(arr[i]));
        maxSUM = max(maxSUM, sum);
    }

    return maxSUM;
}

int getMaxSubArraySumNaive(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
            cout << sum << " " << maxSum << endl;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getMaxSubArraySumNaive(arr, n) << "\n";
    cout << getMaxSumArraySumDP(arr, n) << "\n";
}