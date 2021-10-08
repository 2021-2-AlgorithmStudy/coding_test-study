#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K)
{
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    int cnt = 0;
    while (!pq.empty() && pq.top() < K)
    {
        int n1 = pq.top();
        pq.pop();
        if (pq.empty())
            return -1;
        int n2 = pq.top();
        pq.pop();
        pq.push(n1 + n2 * 2);
        cnt++;
    }
    return cnt;
}