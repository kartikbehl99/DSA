#include <iostream>
using namespace std;

int getSum(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    cout << getSum(5);
}