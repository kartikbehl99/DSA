#include <iostream>
using namespace std;

int allIndices(int *arr, int size, int num, int *output)
{
    if (size == 0)
    {
        return 0;
    }
    int index = allIndices(arr, size - 1, num, output);
    if (arr[size - 1] == num)
    {
        output[index] = size - 1;
        return index + 1;
    }
    return index;
}