#include <cstdio>
using namespace std;
int dp[1000002][2];
int n;
int main()
{
    scanf("%d", &n);
    dp[1][0] = 1;
    dp[1][1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = n;
        if (dp[i - 1][0] != 0 && dp[i - 1][1] + 1 < dp[i][1])
            dp[i][0] = i - 1, dp[i][1] = dp[i - 1][1] + 1;
        if (i % 2 == 0 && dp[i / 2][0] != 0 && dp[i / 2][1] + 1 < dp[i][1])
            dp[i][0] = i / 2, dp[i][1] = dp[i / 2][1] + 1;
        if (i % 3 == 0 && dp[i / 3][0] != 0 && dp[i / 3][1] + 1 < dp[i][1])
            dp[i][0] = i / 3, dp[i][1] = dp[i / 3][1] + 1;
    }
    int answer = n;
    printf("%d\n", dp[answer][1]);
    while (answer != 1)
    {
        printf("%d ", answer);
        answer = dp[answer][0];
    }
    printf("1");
    return 0;
}