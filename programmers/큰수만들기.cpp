#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int flag = 0;
    for (int i = 0; i < number.length() - 1; i++)
    {
        if (number[i] > number[i + 1])
            answer += number[i], flag = 1;
    }
    cout << answer;
    return answer;
}
int main()
{
    solution("hihi", 1);
    return 0;
}