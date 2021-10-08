#include <cstdio>
using namespace std;
int k, n;
int nums[10001];
int max_n = 0;
int answer = 0;
int count_line(long long num)
{
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        result += nums[i] / num;
    }
    return result;
}
int main()
{
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &nums[i]);
        if (max_n < nums[i])
            max_n = nums[i];
    }
    long long min_num = 1, max_num = max_n;
    while (min_num <= max_num)
    {
        long long mid = (min_num + max_num) / 2;
        int cnt = count_line(mid);
        if (cnt >= n)
        {
            if (answer < mid)
                answer = mid;
            min_num = mid + 1;
        }
        else
            max_num = mid - 1;
    }
    printf("%d", answer);
    return 0;
}