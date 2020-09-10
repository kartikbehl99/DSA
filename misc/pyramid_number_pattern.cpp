#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        int val = i + 1;

        for (int j = n; j > i; j--)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << val;
            if (j < (2 * i + 1) / 2)
                val--;
            else
                val++;
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    printPattern(n);
}