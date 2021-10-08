#include <cstdio>
using namespace std;
int n, m;
int nums[101][101];
int sum[101][101];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", nums[i][j]);
            sum[i][j] = (i == 0 ? 0 : sum[i - 1][j]) + (j == 0 ? 0 : sum[i][j - 1]) - ((i != 0 && j != 0 ? sum[i - 1][j - 1] : 0));
        }
    }

    return 0;
}