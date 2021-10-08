#include <cstdio>
using namespace std;
int n, m;
bool prime[1000001];
int main()
{
    scanf("%d%d", &n, &m);
    prime[1] = true;
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2; j * i <= 1000000; j++)
            prime[j * i] = true;
    }

    for (int i = n; i <= m; i++)
    {
        if (!prime[i])
            printf("%d\n", i);
    }
    return 0;
}