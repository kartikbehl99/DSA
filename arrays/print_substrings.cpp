#include <iostream>
#include <string>
using namespace std;

void printSubstrings(string s)
{
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        string temp = "";
        for (int j = i; j < len; j++)
        {
            temp += s[j];
            cout << temp << "\n";
        }
    }
}

void printSubstringsRecursive(string s, string temp = "")
{
    if (s.length() == 0)
    {
        cout << temp << "\n";
        return;
    }

    temp += s[0];
}

int main()
{
    string s;
    cin >> s;

    printSubstrings(s);
}