#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct FISH
{
    int size;
    int r;
    int c;
};
struct NODE
{
    int cnt;
    int r;
    int c;
};
typedef pair<int, int> pii;
struct compare
{
    bool operator()(FISH a, FISH b)
    {
        if (a.size == b.size)
        {
            if (a.r == b.r)
                return a.c > b.c;
            return a.r > b.r;
        }
        return a.size > b.size;
    }
};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pii> q;
queue<FISH> fish_temp;
queue<NODE> check_q;
priority_queue<FISH, vector<FISH>, compare> pq;
int map[21][21];
int n, min_r = 21, min_c = 21, cur_size = 2, cur_cnt = 0, min_cnt = 401, answer = 0;
NODE next_target;
NODE node;
FISH fish_node;

void check_fish(FISH fish, pii shark)
{
    bool check[21][21];
    memset(check, false, sizeof(check));
    node.r = shark.first, node.c = shark.second, node.cnt = 0;
    check_q.push(node);
    while (!check_q.empty())
    {
        NODE cur = check_q.front();
        check_q.pop();

        if (cur.r == fish.r && cur.c == fish.c && cur.cnt <= min_cnt)
        {
            if (cur.cnt != min_cnt)
            {
                next_target = cur;
                min_r = cur.r;
                min_c = cur.c;
                min_cnt = cur.cnt;
            }
            else if (next_target.r >= cur.r)
            {
                if (next_target.r != cur.r || (next_target.r == cur.r && next_target.c > cur.c))
                {
                    next_target = cur;
                    min_r = cur.r;
                    min_c = cur.c;
                    min_cnt = cur.cnt;
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (cur.cnt + 1 <= min_cnt && cur.r + dir[i][0] >= 0 && cur.r + dir[i][0] < n && cur.c + dir[i][1] >= 0 && cur.c + dir[i][1] < n && !check[cur.r + dir[i][0]][cur.c + dir[i][1]] && map[cur.r + dir[i][0]][cur.c + dir[i][1]] <= cur_size)
                {
                    check[cur.r + dir[i][0]][cur.c + dir[i][1]] = true;
                    node.r = cur.r + dir[i][0], node.c = cur.c + dir[i][1], node.cnt = cur.cnt + 1;
                    check_q.push(node);
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9)
            {
                q.push(make_pair(i, j));
                map[i][j] = 0;
            }
            else if (map[i][j] != 0)
            {
                fish_node.r = i, fish_node.c = j, fish_node.size = map[i][j];
                pq.push(fish_node);
            }
        }
    }
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        while (!pq.empty() && pq.top().size < cur_size)
        {
            FISH cur_fish = pq.top();
            pq.pop();
            fish_temp.push(cur_fish);
            check_fish(cur_fish, cur);
        }
        if (min_cnt != 401)
        {
            answer += min_cnt;
            min_cnt = 401;
            min_r = 21;
            min_c = 21;
            cur_cnt++;
            if (cur_cnt == cur_size)
                cur_size++, cur_cnt = 0;

            while (!fish_temp.empty())
            {
                FISH cur_fish = fish_temp.front();
                fish_temp.pop();
                if (next_target.r != cur_fish.r || next_target.c != cur_fish.c)
                    pq.push(cur_fish);
            }
            q.push(make_pair(next_target.r, next_target.c));
        }
    }
    printf("%d", answer);
    return 0;
}