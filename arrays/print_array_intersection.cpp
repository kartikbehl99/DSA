#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int *inputArr(int size1)
{
    int *arr = new int[size1];

    for (int i = 0; i < size1; i++)
    {
        cin >> arr[i];
    }

    return arr;
}

unordered_set<int> createSet(int *arr, int size)
{
    unordered_set<int> s;
    for (int i = 0; i < size; i++)
        s.insert(arr[i]);

    return s;
}

void printIntersection(int *arr1, int size1, int *arr2, int size2)
{
    unordered_set<int> s1 = createSet(arr1, size1);
    unordered_set<int> s2 = createSet(arr2, size2);

    unordered_map<int, int> freq;
    for (int i : s1)
    {
        freq[i]++;
    }
    for (int i : s2)
    {
        freq[i]++;
    }

    for (pair<int, int> i : freq)
    {
        if (i.second == 2)
            cout << i.first << " ";
    }
    cout << "\n";
}

int main()
{
    int size1, size2;
    cin >> size1;
    int *arr1 = inputArr(size1);
    cin >> size2;
    int *arr2 = inputArr(size2);

    printIntersection(arr1, size1, arr2, size2);
}