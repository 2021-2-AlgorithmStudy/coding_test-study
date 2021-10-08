#include <cstdio>
#include <vector>
using namespace std;
int n, m;
bool check[10];
vector<int> v;
void back_tracking(int cnt)
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
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            v.push_back(i);
            back_tracking(cnt + 1);
            v.pop_back();
            check[i] = false;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    back_tracking(0);
    return 0;
}