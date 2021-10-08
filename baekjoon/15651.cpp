#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
bool check[10];
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
        v.push_back(i);
        back_tracking(cnt + 1);
        v.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    back_tracking(0);
    return 0;
}