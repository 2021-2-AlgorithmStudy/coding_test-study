#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int cur_member_check[100001];
vector<int> member;
queue<int> q;
int t, n, m, cur_member, next_member;
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        member.push_back(0);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &m);
            member.push_back(m);
            if (j != m)
                q.push(j);
        }
        memset(cur_member_check, 0, sizeof(cur_member_check));
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cur_member = cur;
            next_member = member[cur];
            while (cur_member != next_member && (cur_member_check[cur_member] == cur || !cur_member_check[cur_member]))
            {
                cur_member_check[cur_member] = cur;
                cur_member = next_member;
                next_member = member[cur_member];

                if (cur_member_check[cur_member] == cur)
                    member[cur_member] = cur_member;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (member[j] != j)
                cnt++;
        }
        printf("%d\n", cnt);
        member.clear();
    }
    return 0;
}