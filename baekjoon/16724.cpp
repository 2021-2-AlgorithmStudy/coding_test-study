#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}}; // U, D, L, R
int n, m, cnt = 0;
char map[1001][1001];
int check[1001][1001];
queue<pii> q;
int check_dir(char c)
{
    if (c == 'U')
        return 0;
    if (c == 'D')
        return 1;
    if (c == 'L')
        return 2;
    if (c == 'R')
        return 3;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] == 0)
            {
                cnt++;
                int row = i, col = j;
                while (1)
                {
                    check[row][col] = cnt;
                    q.push(make_pair(row, col));
                    int dir_num = check_dir(map[row][col]);
                    row += dir[dir_num][0];
                    col += dir[dir_num][1];
                    if (check[row][col] == cnt)
                        break;
                    else if (check[row][col])
                    {
                        cnt--;
                        while (!q.empty())
                        {
                            pii cur = q.front();
                            q.pop();
                            check[cur.first][cur.second] = cnt;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}