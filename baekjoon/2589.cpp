#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
struct NODE
{
    int r;
    int c;
    int cnt;
};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char map[51][51];
bool check[51][51];
queue<NODE> q;
int n, m, answer = 0;
NODE temp;
void bfs()
{
    NODE cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (answer < cur.cnt)
            answer = cur.cnt;
        for (int i = 0; i < 4; i++)
        {
            if (cur.r + dir[i][0] >= 0 && cur.r + dir[i][0] < n && cur.c + dir[i][1] >= 0 && cur.c + dir[i][1] < m && !check[cur.r + dir[i][0]][cur.c + dir[i][1]] && map[cur.r + dir[i][0]][cur.c + dir[i][1]] == 'L')
            {
                check[cur.r + dir[i][0]][cur.c + dir[i][1]] = true;
                temp.r = cur.r + dir[i][0], temp.c = cur.c + dir[i][1], temp.cnt = cur.cnt + 1;
                q.push(temp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = false;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &map[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'L')
            {
                temp.r = i, temp.c = j, temp.cnt = 0;
                check[i][j] = true;
                q.push(temp);
                bfs();
            }
        }
    printf("%d", answer);
    return 0;
}