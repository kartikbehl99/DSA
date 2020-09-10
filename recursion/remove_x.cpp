#include <iostream>
#include <cstring>
using namespace std;

void removeX(char *input, char x)
{
    if (input[0] == '\0')
        return;

    removeX(input + 1, x);

    if (input[0] == x)
    {
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            input[i] = input[i + 1];
        }
    }
}

int main()
{
    char input[7] = "axxaaa";
    removeX(input, 'x');
    cout << input << endl;
}