#include <cstdio>
using namespace std;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    int low = 1, high = 1000000000, mid, cnt, answer;
    while (low <= high)
    {
        cnt = 0;
        mid = (low + high) / 2;
        for (int i = 1; i <= n; i++)
            cnt += mid / i > n ? n : mid / i;
        if (cnt < k)
            low = mid + 1;
        // 이 cnt 범위가 되어야지 답이 될 가능성이 있다.
        // 그리고 같은 숫자가 여러개가 있어서 딱 k==cnt로 안떨어질 수도 있음!
        // 그래서 범위를 가장 좁혀가서 여기에 해당하는 마지막 mid가 답이다!
        else if (cnt >= k)
            answer = mid,
            high = mid - 1;
    }
    printf("%lld", answer);
    return 0;
}