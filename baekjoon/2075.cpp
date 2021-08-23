#include <queue>
#include <cstdio>
using namespace std;
struct N_INFO
{
    int row, col, num;
};
int nums[1501][1501];
int n, answer;
N_INFO temp;
vector<int> v;
struct compare
{
    bool operator()(const N_INFO &a, const N_INFO &b)
    {
        return a.num < b.num;
    }
};
priority_queue<N_INFO, vector<N_INFO>, compare> pq;
void set_temp(int row, int col, int num)
{
    temp.row = row, temp.col = col, temp.num = num;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &nums[i][j]);
            if (i == n - 1)
            {
                set_temp(i, j, nums[i][j]);
                pq.push(temp);
            }
        }
    }
    while (n--)
    {
        answer = pq.top().num;
        if (pq.top().row - 1 >= 0)
        {
            set_temp(pq.top().row - 1, pq.top().col, nums[pq.top().row - 1][pq.top().col]);
            pq.push(temp);
        }
        pq.pop();
    }
    printf("%d", answer);
    return 0;
}