#include <cstdio>
using namespace std;
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    int temp_m = m;
    while (m)
    {
        printf("%d\n", n * (m % 10));
        m /= 10;
    }
    printf("%d\n", n * temp_m);
    return 0;
}