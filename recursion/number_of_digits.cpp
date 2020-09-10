#include <iostream>
using namespace std;

int getNumDigits(int num)
{
    if (num == 0)
        return 0;
    return 1 + getNumDigits(num / 10);
}

int main()
{
    int num = -123456;

    cout << getNumDigits(num) << "\n";
}