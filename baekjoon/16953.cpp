#include <cstdio>
#include <queue>
using namespace std;
typedef pair<long long, int> pli;
int a, b;
queue<pli> q;
int main()
{
    scanf("%d%d", &a, &b);
    q.push(make_pair(a, 1));
    while (!q.empty())
    {
        pli cur = q.front();
        q.pop();
        if (cur.first == b)
        {
            printf("%d", cur.second);
            return 0;
        }
        if (cur.first * 2 <= b)
            q.push(make_pair(cur.first * 2, cur.second + 1));
        if (cur.first * 10 + 1 <= b)
            q.push(make_pair(cur.first * 10 + 1, cur.second + 1));
    }
    printf("-1");
    return 0;
}