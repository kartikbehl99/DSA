#include <iostream>
using namespace std;

void printPattern(int n)
{
    int starCount = 0;
    int startStartPos = n;
    for (int i = 0; i < n; i++)
    {
        int val = 1;
        for (int j = 0; j < 2 * n; j++)
        {
            if (starCount && (j >= startStartPos && j < startStartPos + starCount))
            {
                cout << "*";
            }
            else
            {
                cout << val;
            }

            if (j < n)
                val++;

            else
                val--;
        }
        cout << "\n";
        starCount += 2;
        startStartPos -= 1;
    }
}

int main()
{
    int n;
    cin >> n;

    printPattern(n);
}