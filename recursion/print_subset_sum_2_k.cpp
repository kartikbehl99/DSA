#include <iostream>
using namespace std;

void printSubsetSum2K(int *arr, int n, int k, int *output, int outputSize = 0)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < outputSize; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    printSubsetSum2K(arr + 1, n - 1, k, output, outputSize);

    output[outputSize++] = arr[0];

    printSubsetSum2K(arr + 1, n - 1, k - arr[0], output, outputSize);
}

int main()
{
    int arr[9] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int output[100];

    printSubsetSum2K(arr, 9, 6, output);
}