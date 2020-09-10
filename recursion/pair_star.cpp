#include <iostream>
using namespace std;

void pairStar(string &input)
{
    int len = input.length();
    if (len == 0)
        return;

    string s = input.substr(1);
    pairStar(s);

    if (input[0] == input[1])
    {
        for (int i = len - 1; i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
}

int main()
{
    string input = "hello";
    pairStar(input);
    cout << input << endl;
}