#include <iostream>
#include <string>
using namespace std;

string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int returnKeypad(int num, string output[])
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    string smallOutput[1000];
    int size = returnKeypad(num / 10, smallOutput);

    int digit = num % 10;

    int index = 0;
    for (int i = 0; i < keypad[digit].length(); i++)
    {
        char ch = keypad[digit][i];

        for (int i = 0; i < size; i++)
        {
            output[index++] = smallOutput[i] + ch;
        }
    }

    return 3 * size;
}

int main()
{
    string output[1000];

    int size = returnKeypad(234, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }
}