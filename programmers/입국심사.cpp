#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 1000000000000000000;
    long long s = 0, e = 1000000000000000000, mid;
    while (s <= e)
    {
        unsigned long long cnt = 0;
        mid = (s + e) / 2;
        printf("%lld\n", mid);
        for (int i = 0; i < times.size(); i++)
        {
            cnt += (mid / times[i]);
        }
        printf("cnt: %lld\n", cnt);
        if (cnt < n)
            s = mid + 1;
        else
        {
            e = mid - 1;
            if (n == cnt && mid < answer)
                answer = mid;
        }
    }
    return answer;
}
int main()
{
    vector<int> v = {1, 1};
    printf("%lld", solution(11, v));
    return 0;
}