// sds 중앙값 복기
#include <cstdio>
#include <queue>
using namespace std;
int t, m, num, min_swap, max_swap;
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        priority_queue<int, vector<int>, greater<int> > min_pq;
        priority_queue<int> max_pq;
        scanf("%d", &m);
        printf("%d\n", (m + 1) / 2);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            if (min_pq.empty())
                min_pq.push(num);
            else if (min_pq.size() <= max_pq.size())
                min_pq.push(num);
            else
                max_pq.push(num);
            // 한쪽 pq에 쌓여서 다른 pq로 넣어주는 과정에서 min, max heap의 top의 크기가 꼬이는 경우가 있다..!
            if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
            {
                min_swap = min_pq.top();
                max_swap = max_pq.top();
                min_pq.pop();
                max_pq.pop();
                min_pq.push(max_swap);
                max_pq.push(min_swap);
            }
            if (j % 2 == 0)
                printf("%d ", min_pq.top());
        }
        printf("\n");
    }

    return 0;
}