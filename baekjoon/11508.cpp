#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, num;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<int>());
    int cur_sum = 0, total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if ((i + 1) % 3 == 0)
        {
            total += cur_sum;
            cur_sum = 0;
        }
        else
            cur_sum += v[i];
    }
    total += cur_sum;
    printf("%d", total);
    return 0;
}