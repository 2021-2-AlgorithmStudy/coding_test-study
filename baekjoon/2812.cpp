#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k;
string str, result = "";
vector<char> s;
int main()
{
    scanf("%d%d", &n, &k);
    cin >> str;
    int c = 0;
    s.push_back(str[0]);
    for (int i = 1; i < n && c <= k; i++)
    {
        while (c < k && !s.empty() && s.back() < str[i])
            s.pop_back(), c++;
        s.push_back(str[i]);
    }
    while (c < k)
        s.pop_back(), c++;
    for (int i = 0; i < s.size(); i++)
        printf("%c", s[i]);
    return 0;
}