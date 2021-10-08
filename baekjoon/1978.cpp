#include <cstdio>
#include <math.h>
using namespace std;
int n, num, cnt = 0;
int main()
{
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        scanf("%d", &num);
        for (int j = 2; j <= sqrt(num); j++)
        {
            if (num % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && num != 1)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}