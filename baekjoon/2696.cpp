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
            else if (min_pq.top() <= num)
            {
                if (min_pq.size() > max_pq.size())
                {
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                }
                min_pq.push(num);
            }
            else
            {
                if (min_pq.size() < max_pq.size())
                {
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                }
                max_pq.push(num);
            }
            // 한쪽 pq에 너무 많이 쌓여서 옮기고 넣어주는 과정에서 min, max heap의 top의 크기가 꼬이는 경우가 있다..! -> test case 3번
            // 옮기고 새로 넣어주는 경우 무조건 min, max pq가 같은 수로 쌓이기 때문에 그냥 min pq에 있던거만 max로 옮겨준다.
            if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
            {
                min_swap = min_pq.top();
                min_pq.pop();
                max_pq.push(min_swap);
            }
            if (j % 2 == 0)
                printf("%d ", min_pq.size() > max_pq.size() ? min_pq.top() : max_pq.top());
        }
        printf("\n");
    }

    return 0;
}