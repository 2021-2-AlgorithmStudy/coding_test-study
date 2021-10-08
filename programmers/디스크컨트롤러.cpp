#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
priority_queue<pii, vector<pii>, greater<pii> > min_pq; // first: 걸리는 시간, second: 요청 시간
int solution(vector<vector<int> > jobs)
{
    int answer = 0;
    sort(jobs.begin(), jobs.end(), compare);
    int time = 0, wait_time = 0;
    int i = 0;
    while (time <= 1001000)
    {
        while (i < jobs.size() && jobs[i][0] <= time)
            min_pq.push(make_pair(jobs[i][1], jobs[i][0])), i++;
        if (!min_pq.empty())
        {
            pii cur = min_pq.top();
            min_pq.pop();
            wait_time += time - cur.second + cur.first;
            time += cur.first;
        }
        else
            time++;
    }
    answer = wait_time / jobs.size();
    return answer;
}
int main()
{
    vector<vector<int> > v = {{0, 3}, {1, 9}, {2, 6}};
    solution(v);
    return 0;
}