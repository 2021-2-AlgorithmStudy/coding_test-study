#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, cnt = 0;
priority_queue<int> pq;
vector<pii> v;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pii cur = v[i];
        // if (pq.empty())
        //     pq.push(-cur.second);
        // else
        // {
        //     if (-pq.top() > cur.first)
        //     {
        //         pq.push(-cur.second);
        //         if (pq.size() > cnt)
        //             cnt = pq.size();
        //     }
        //     else
        //     {
        //         pq.pop();
        //         pq.push(-cur.second);
        //     }
        // }
        if (!pq.empty())
        {
            if (-pq.top() > cur.first)
                cnt = pq.size() + 1;
            else
                pq.pop();
        }
        pq.push(-cur.second);
    }
    printf("%d", cnt);

    return 0;
}