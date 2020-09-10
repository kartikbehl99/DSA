#include <iostream>
using namespace std;

void printPattern(int n)
{
    int pos1 = 0;
    int pos2 = (2 * n + 1) / 2;
    int pos3 = 2 * n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            if (j == pos1 || j == pos2 || j == pos3)
            {
                cout << "*";
                continue;
            }
            cout << "0";
        }
        pos1++;
        pos3--;
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    printPattern(n);
}