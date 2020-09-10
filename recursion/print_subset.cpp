#include <iostream>
using namespace std;

void printSubsetsUtil(int *arr, int n, int *output, int outputSize = 0)
{
    if (n == 0)
    {
        for (int i = 0; i < outputSize; i++)
        {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }

    printSubsetsUtil(arr + 1, n - 1, output, outputSize);

    output[outputSize] = arr[0];

    printSubsetsUtil(arr + 1, n - 1, output, outputSize + 1);
}

void printSubsets(int *arr, int n)
{
    int output[10000];
    printSubsetsUtil(arr, n, output);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    printSubsets(arr, 5);
}