#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e)
{
    int *arr3 = new int[e - s + 1];
    int index = 0;

    int i1 = s;
    int i2 = mid + 1;

    while (i1 <= mid && i2 <= e)
    {
        if (arr[i1] < arr[i2])
            arr3[index++] = arr[i1++];
        else
            arr3[index++] = arr[i2++];
    }

    while (i1 <= mid)
    {
        arr3[index++] = arr[i1++];
    }

    while (i2 <= e)
    {
        arr3[index++] = arr[i2++];
    }

    index = 0;
    for (int i = s; i <= e; i++)
    {
        arr[i] = arr3[index++];
    }
}

void mergeSortUtil(int *arr, int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;

        mergeSortUtil(arr, s, mid);
        mergeSortUtil(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

void mergeSort(int *arr, int n)
{
    int s = 0;
    int e = n - 1;

    mergeSortUtil(arr, s, e);
}

int main()
{
    int arr[5] = {1, 5, 3, 2, 6};

    mergeSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}