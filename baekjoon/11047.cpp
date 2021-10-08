#include <cstdio>
using namespace std;
int n, k, cnt = 0;
int money[11];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &money[i]);
    }
    while (n)
    {
        n--;
        while (k - money[n] >= 0)
        {
            k -= money[n];
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}