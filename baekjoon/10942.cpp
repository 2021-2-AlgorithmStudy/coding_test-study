#include <cstdio>
using namespace std;
int dp[2002][2002];
int nums[2002];
int n, m;
int check(int s, int e)
{
    if (s == e || s > e)
        return 1;
    if (dp[s][e] != 0)
        return dp[s][e];
    else if (nums[s] == nums[e])
        return dp[s][e] = check(s + 1, e - 1);
    else if (nums[s] != nums[e])
        return dp[s][e] = -1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        int result = check(s, e) == -1 ? 0 : 1;
        printf("%d\n", result);
    }
    return 0;
}