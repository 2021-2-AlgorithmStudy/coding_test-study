#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int n, num;
vector<int> v;
vector<int> tree[10];
void make_tree(int left, int right, int cnt)
{
    if (cnt == n)
        return;
    int mid = (left + right) / 2;
    tree[cnt].push_back(v[mid]);
    make_tree(left, mid - 1, cnt + 1);
    make_tree(mid + 1, right, cnt + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < pow(2, n) - 1; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    make_tree(0, v.size() - 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }
    return 0;
}