#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
string ex_str;
char v[1000001];
int ptr = 0;
void check_str()
{
    for (int i = 0; i < ex_str.length(); i++)
    {
        if (ptr - i < 0 || v[ptr - i] != ex_str[ex_str.length() - 1 - i])
            return;
    }
    ptr -= ex_str.length();
}
int main()
{
    cin >> str;
    cin >> ex_str;
    for (int i = 0; i < str.length(); i++)
    {
        v[ptr] = str[i];
        if (str[i] == ex_str[ex_str.length() - 1])
            check_str();
        ptr++;
    }
    if (ptr == 0)
        cout << "FRULA";
    for (int i = 0; i < ptr; i++)
    {
        cout << v[i];
    }
    return 0;
}