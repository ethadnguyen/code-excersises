#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int isEvenOrOdd(char s)
{
    return s % 2 == 0 ? 0 : 1;
}
string divBy2(string s)
{
    int new_digit;
    string new_s("");
    int add = 0;
    for (int i = 0; i < s.size(); i++)
    {
        new_digit = ((int)s[i] - (int)'0') / 2 + add;
        add = isEvenOrOdd(s[i]) * 5;
        new_s += to_string(new_digit);
    }
    while (new_s[0] == '0')
    {
        new_s.erase(new_s.begin());
    }
    return new_s;
}
int main()
{
    string num;
    string binary = "";
    cin >> num;
    while (num != "")
    {
        binary += to_string(isEvenOrOdd(num[num.size() - 1]));
        num = divBy2(num);
    }
    reverse(binary.begin(), binary.end());
    cout << endl;
    cout << binary;
    return 0;
}