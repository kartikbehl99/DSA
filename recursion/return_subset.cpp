#include <iostream>
using namespace std;

int subset(int *input, int size, int output[][20])
{
    if (size == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallOutput[1000][20];
    int smallSize = subset(input, size - 1, smallOutput);

    for (int i = 0; i < smallSize; i++)
    {
        for (int j = 0; j <= smallOutput[i][0]; j++)
        {
            output[i][j] = smallOutput[i][j];
        }
    }
    int index = smallSize;
    for (int i = 0; i < smallSize; i++)
    {
        output[index][0] = smallOutput[i][0] + 1;
        output[index][1] = input[size - 1];
        int col = 2;
        for (int j = 1; j <= smallOutput[i][0]; j++)
        {
            output[index][col++] = smallOutput[i][j];
        }
        index++;
    }

    return 2 * smallSize;
}

int main()
{
    int output[1000][20];
    int input[5] = {1, 2, 3, 4, 5};
    int size = subset(input, 5, output);

    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; output[i][j] != 0; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}