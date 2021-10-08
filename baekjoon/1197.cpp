#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct NODE
{
    int w;
    int n1;
    int n2;
};
vector<NODE> v;
int p[100001];
int V, E, w, n1, n2, sum = 0, p1, p2;
NODE temp;
bool compare(NODE a, NODE b)
{
    return a.w < b.w;
}
int find(int num)
{
    if (num == p[num])
        return num;
    return p[num] = find(p[num]);
}
int main()
{
    scanf("%d%d", &V, &E);
    for (int i = 1; i <= V; i++)
        p[i] = i;

    for (int i = 0; i < E; i++)
    {
        scanf("%d%d%d", &n1, &n2, &w);
        temp.w = w, temp.n1 = n1, temp.n2 = n2;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < E; i++)
    {
        p1 = find(v[i].n1), p2 = find(v[i].n2);
        if (p1 != p2)
            sum += v[i].w;
        p[p2] = p1;
    }
    printf("%d", sum);
    return 0;
}