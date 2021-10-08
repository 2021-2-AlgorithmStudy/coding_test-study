#include <cstdio>
using namespace std;

int nums[100001];
int n, m, n1, n2;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &n1, &n2);
        printf("%d\n", nums[n2] - nums[n1 - 1]);
    }
    return 0;
}