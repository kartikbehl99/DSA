#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
    int length = s.length();
    if (length == 0)
        return true;

    if (s[0] == 'a')
    {
        if (length == 1)
        {
            return true;
        }
        else if (s[1] == 'a')
        {
            return check(s.substr(1));
        }
        else if (s[1] == 'b' && s[2] == 'b')
        {
            return check(s.substr(1));
        }
    }
    else if (s[0] == 'b' && s[1] == 'b')
    {
        if (length - 2 == 0)
        {
            return true;
        }
        if (s[2] == 'a')
        {
            return check(s.substr(2));
        }
    }

    return false;
}

int main()
{
    string s = "abbabbabba";
    cout << check(s) << "\n";
}