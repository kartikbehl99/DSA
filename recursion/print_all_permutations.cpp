#include <iostream>
#include <string>
using namespace std;

void printAllPermutations(string input, string output)
{
    int length = input.length();
    if (length == 0)
    {
        cout << output << "\n";
        return;
    }

    for (int i = 0; i < length; i++)
    {
        string temp = input.substr(0, i) + input.substr(i + 1);
        string smallOutput = input[i] + output;
        printAllPermutations(temp, smallOutput);
    }
}

int main()
{
    string s = "abc";

    printAllPermutations(s, "");
}