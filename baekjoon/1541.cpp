#include <iostream>
#include <string>

using namespace std;
string str, num = "0";
int flag = 1;
int pr = 1;
int sum = 0;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            sum += pr * stoi(num);
            num = "0";
            pr = -1;
            flag = -1;
        }
        else if (str[i] == '+')
        {
            sum += pr * stoi(num);
            num = "0";
            pr = flag;
        }
        else
            num += str[i];
    }
    printf("%d", sum + pr * stoi(num));
    return 0;
}