#include <bits/stdc++.h>
using namespace std;

string numToStr(int n)
{
    if (n == 0)
        return "0";

    string ans = "";

    while (n)
    {
        int digit = n % 10;
        ans += char(digit) + 48;
        n /= 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

long long strToNum(string s)
{
    long long num = 0;

    for (char c : s)
    {
        num *= 10;
        num += int(c) - 48;
        num %= 1000000007;
    }

    return num;
}

long long solve(string num, int index, string s)
{
    if (index == num.length())
    {
        if (s.length() == index)
            return 0;
        return strToNum(s) % 1000000007;
    }

    long long notInclude = solve(num, index + 1, s);
    s += num[index];
    long long include = solve(num, index + 1, s);

    return (notInclude % 1000000007 + include % 1000000007) % 1000000007;
}

long long solve(string n)
{
    return (solve(n, 0, "")) % 100000007;
}

int main()
{
    string n;
    cin >> n;
    cout << solve(n) << "\n";
}