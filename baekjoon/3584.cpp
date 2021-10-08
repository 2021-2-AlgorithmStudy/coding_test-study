#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n, t, n1, n2, root;
struct NODE
{
    vector<int> child;
    int parent;
    int depth;
};
bool check[10001];
NODE v[10001];
queue<int> q;
int change_depth(int node, int depth)
{
    int next_node = node;
    while (depth--)
        next_node = v[next_node].parent;
    return next_node;
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        //init
        for (int j = 1; j <= n; j++)
            v[j].child.clear();
        memset(check, false, n + 1);
        for (int j = 1; j <= n - 1; j++)
        {
            scanf("%d%d", &n1, &n2);
            v[n1].child.push_back(n2);
            v[n2].parent = n1;
            check[n2] = true;
        }
        //find root -> 굳이 이렇게 해야할까..? 다른 방법 놉?
        for (int j = 1; j <= n; j++)
        {
            if (!check[j])
            {
                root = j;
                break;
            }
        }
        v[root].parent = 0;
        v[root].depth = 1;
        q.push(root);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].child.size(); j++)
            {
                v[v[cur].child[j]].depth = v[cur].depth + 1;
                q.push(v[cur].child[j]);
            }
        }
        scanf("%d%d", &n1, &n2);
        if (v[n1].depth > v[n2].depth)
            n1 = change_depth(n1, v[n1].depth - v[n2].depth);
        else
            n2 = change_depth(n2, v[n2].depth - v[n1].depth);
        while (n1 != n2)
            n1 = change_depth(n1, 1), n2 = change_depth(n2, 1);
        printf("%d\n", n1);
    }
    return 0;
}