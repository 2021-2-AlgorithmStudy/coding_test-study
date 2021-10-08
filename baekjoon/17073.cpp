#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
bool check[500001];
queue<int> q;
vector<int> v[500001];
int n, w;
int n1, n2, leaf_cnt = 0;
int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &n1, &n2);
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    q.push(1);
    check[1] = true;
    while (!q.empty())
    {
        int flag = 0;
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (!check[v[cur][i]])
            {
                check[v[cur][i]] = true;
                q.push(v[cur][i]);
                flag = 1;
            }
        }
        if (!flag)
            leaf_cnt++;
    }
    printf("%lf", (double)w / (double)leaf_cnt);
    return 0;
}