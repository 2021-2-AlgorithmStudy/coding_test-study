#include <cstdio>
using namespace std;
int n, cnt = 0;
int main()
{
    scanf("%d", &n);
    while (n - 5 >= 0)
        cnt++, n -= 5;
    if (cnt && n % 2 == 1)
        cnt--, n += 5;
    while (n - 2 >= 0)
        cnt++, n -= 2;
    if (n != 0)
        printf("-1");
    else
        printf("%d", cnt);

    return 0;
}