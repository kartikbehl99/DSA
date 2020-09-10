#include <iostream>
#include <string>
using namespace std;

string codes[27] = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int getCodes(string input, string output[1000])
{
    int length = input.length();

    if (length == 0)
    {
        output[0] = "";
        return 1;
    }

    if (length == 1)
    {
        int index = int(input[0]) - 48;
        output[0] = codes[index];
        return 1;
    }

    string smallOutput1[1000];
    int smallOutputSize1 = getCodes(input.substr(1), smallOutput1);
    string smallOutput2[1000];
    int smallOutputSize2 = getCodes(input.substr(2), smallOutput2);

    int index = 0;
    int ci = int(input[0]) - 48;
    for (int i = 0; i < smallOutputSize1; i++)
    {
        output[index] = codes[ci] + smallOutput1[i];
        index++;
    }

    if (length >= 2)
    {
        ci = (int(input[0]) - 48) * 10 + (int(input[1]) - 48);

        if (ci > 26)
        {
            return index;
        }

        for (int i = 0; i < smallOutputSize2; i++)
        {
            output[index] = codes[ci] + smallOutput2[i];
            index++;
        }
    }

    return index;
}

int main()
{
    string input = "1123";
    string output[1000];

    int size = getCodes(input, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << "\n";
    }
}