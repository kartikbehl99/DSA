#include <iostream>
#include <string>

using namespace std;

string codes[27] = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void printAllCodes(string input, string output = "")
{
    int length = input.length();
    if (length == 0 || length == 1)
    {
        cout << output << "\n";
        return;
    }

    int ci = int(input[0]) - 48;
    string smallOutput = output + codes[ci];
    printAllCodes(input.substr(1), smallOutput);

    ci = (int(input[0]) - 48) * 10 + (int(input[1]) - 48);
    smallOutput = output + codes[ci];
    printAllCodes(input.substr(2), smallOutput);
}

int main()
{
    string input = "1123";
    printAllCodes(input);
}