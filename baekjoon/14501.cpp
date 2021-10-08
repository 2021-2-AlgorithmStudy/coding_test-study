#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int n, t, p, answer = 0;
void back_tracking(int day, int sum)
{
    if (sum > answer)
        answer = sum;

    for (int i = day; i <= n; i++)
    {
        if (i + v[i].first - 1 <= n)
            back_tracking(i + v[i].first, sum + v[i].second);
    }
}
int main()
{
    scanf("%d", &n);
    v.push_back(make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &t, &p);
        v.push_back(make_pair(t, p));
    }
    back_tracking(1, 0);
    printf("%d", answer);
    return 0;
}