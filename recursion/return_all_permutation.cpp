#include <iostream>
#include <string>
using namespace std;

int getAllPermutations(string input, string output[10000])
{
    int length = input.length();
    if (length == 0 || length == 1)
    {
        output[0] = input;
        return 1;
    }

    int index = 0;

    for (int i = 0; i < length; i++)
    {
        string temp = input.substr(0, i) + input.substr(i + 1);
        string smallOutput[10000];
        int size = getAllPermutations(temp, smallOutput);

        for (int j = 0; j < size; j++)
        {
            output[index++] = input[i] + smallOutput[j];
        }
    }

    return index;
}

int main()
{
    string s = "abc";
    string output[10000];

    int size = getAllPermutations(s, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << "\n";
    }
}