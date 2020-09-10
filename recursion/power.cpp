#include <iostream>
using namespace std;

int getPower(int x, int n)
{
    if (n == 0)
        return 1;

    int temp = getPower(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    return x * temp * temp;
}

int main()
{
    cout << getPower(3, 4) << "\n";
}