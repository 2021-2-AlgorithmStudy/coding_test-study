#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, num, sum = 0;
vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    sum = v[0];
    if (sum != 1)
    {
        printf("1");
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1] * 2 && sum + 1 < v[i])
            break;
        sum += v[i];
    }
    printf("%d", sum + 1);
    return 0;
}