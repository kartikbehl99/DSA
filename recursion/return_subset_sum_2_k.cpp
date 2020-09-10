#include <iostream>
using namespace std;

int returnSubsetSumToK(int *arr, int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }

    int smallOutput1[1000][50];
    int smallOutputSize1 = returnSubsetSumToK(arr + 1, n - 1, smallOutput1, k - arr[0]);
    int smallOutput2[1000][50];
    int smallOutputSize2 = returnSubsetSumToK(arr + 1, n - 1, smallOutput2, k);

    int index = 0;
    for (int i = 0; i < smallOutputSize2; i++)
    {
        for (int j = 0; j <= smallOutput2[i][0]; j++)
        {
            output[index][j] = smallOutput2[i][j];
        }
        index++;
    }

    for (int i = 0; i < smallOutputSize1; i++)
    {
        output[index][0] = smallOutput1[i][0] + 1;
        output[index][1] = arr[0];

        for (int j = 1; j <= smallOutput1[i][0]; i++)
        {
            output[index][j + 1] = smallOutput1[i][j];
        }
        index++;
    }

    return index;
}

int main()
{
    int arr[9] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int output[1000][50];
    int size = returnSubsetSumToK(arr, 9, output, 6);
    cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
}