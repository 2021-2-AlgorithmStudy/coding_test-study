#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
int p[100002];
vector<int> v[100002];
queue<int> q;
int main()
{
    scanf("%d", &n);
    p[1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (p[v[cur][i]] == 0)
            {
                p[v[cur][i]] = cur;
                q.push(v[cur][i]);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", p[i]);
    }
    return 0;
}