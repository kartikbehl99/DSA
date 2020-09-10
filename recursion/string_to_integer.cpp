#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int stringToInteger(string s)
{
    if (s.length() == 0)
        return 0;

    return (int(s[0]) - 48) * pow(10, s.length() - 1) + stringToInteger(s.substr(1));
}

int main()
{
    cout << stringToInteger("01234560") << endl;
}