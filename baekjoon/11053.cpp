#include <cstdio>
using namespace std;
int dp[1001];
int nums[1001];
int n, answer;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int cur_max = 0;
        scanf("%d", &nums[i]);
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                cur_max = cur_max < dp[j] ? dp[j] : cur_max;
            }
        }
        dp[i] = cur_max + 1;
        answer = answer < dp[i] ? dp[i] : answer;
    }
    printf("%d", answer);
    return 0;
}