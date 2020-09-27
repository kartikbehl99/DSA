#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
    if (row <= 0 || col <= 0)
        return 0;

    int size = min(row, col);

    int maxSize = max(findMaxSquareWithAllZeros(arr, row - 1, col - 1), max(findMaxSquareWithAllZeros(arr, row - 1, col), findMaxSquareWithAllZeros(arr, row, col - 1)));

    bool hasAll0s = true;
    int s;
    for (s = 0; s < size; s++)
    {
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (arr[i][j] != 0)
                {
                    hasAll0s = false;
                    break;
                }
            }
        }
    }

    return max(s, maxSize);
}