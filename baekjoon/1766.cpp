#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, m, pr, ne;
vector<int> v[32001];
int insert_check[32001];
bool solved_check[32001];
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &pr, &ne);
        v[pr].push_back(ne);
        insert_check[ne]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (insert_check[i] == 0)
        {
            pq.push(i);
            solved_check[i] = true;
        }
    }
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (!solved_check[v[cur][i]])
            {
                insert_check[v[cur][i]]--;
                if (insert_check[v[cur][i]] == 0)
                {
                    pq.push(v[cur][i]);
                    solved_check[v[cur][i]] = true;
                }
            }
        }
        printf("%d ", cur);
    }
    return 0;
}