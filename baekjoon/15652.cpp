#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void back_tracking(int prev, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    int i = prev;
    for (; i <= n; i++)
    {
        v.push_back(i);
        back_tracking(i, cnt + 1);
        v.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    back_tracking(1, 0);
    return 0;
}