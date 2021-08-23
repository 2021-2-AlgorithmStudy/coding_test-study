#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> pii;
struct compare
{
    bool operator()(pii a, pii b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
int n, m, p, l, r;
string cmd;
priority_queue<pii> max_pq;                       // second: problem num, first: level
priority_queue<pii, vector<pii>, compare> min_pq; // second: problem num, first: level
int check[100001];
int problem_levels[100001];
void do_command(string cmd)
{
    if (cmd[0] == 'r')
    {
        cin >> r;
        if (r == 1)
        {
            while (check[max_pq.top().second] == max_pq.top().first)
                max_pq.pop();
            cout << max_pq.top().second << '\n';
        }
        else
        {
            while (check[min_pq.top().second] == min_pq.top().first)
                min_pq.pop();

            cout << min_pq.top().second << '\n';
        }
    }
    else if (cmd[0] == 'a')
    {
        cin >> p >> l;
        problem_levels[p] = l;
        max_pq.push(make_pair(l, p));
        min_pq.push(make_pair(l, p));
    }
    else if (cmd[0] == 's')
    {
        cin >> p;
        check[p] = problem_levels[p];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> l;
        problem_levels[p] = l;
        max_pq.push(make_pair(l, p));
        min_pq.push(make_pair(l, p));
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd;
        do_command(cmd);
    }
    return 0;
}