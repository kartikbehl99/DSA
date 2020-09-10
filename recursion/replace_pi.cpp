#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[])
{
    if (input[0] == '\0')
        return;

    replacePi(input + 1);

    if (input[0] == 'p' && input[1] == 'i')
    {
        input[0] = '3';
        input[1] = '.';

        int len = strlen(input);
        for (int i = len; i >= 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[2] = '1';
        input[3] = '4';
    }
}

int main()
{
    char input[7] = "piaapi";
    replacePi(input);
    cout << input << endl;
}