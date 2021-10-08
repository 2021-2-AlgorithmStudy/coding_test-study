#include <cstdio>
#include <algorithm>
using namespace std;
int t, n;
int nums[100001][2];
int dp[100001][2];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n * 2; i++)
        {
            scanf("%d", &nums[i % n][i / n]);
        }

        dp[0][0] = nums[0][0];
        dp[1][0] = nums[0][1] + nums[1][0];
        dp[0][1] = nums[0][1];
        dp[1][1] = nums[0][0] + nums[1][1];
        for (int i = 2; i < n; i++)
        {
            dp[i][0] = max(dp[i - 2][1] + nums[i][0], dp[i - 1][1] + nums[i][0]);
            dp[i][1] = max(dp[i - 2][0] + nums[i][1], dp[i - 1][0] + nums[i][1]);
        }
        printf("%d\n", max(dp[n - 1][0], dp[n - 1][1]));
    }
    return 0;
}