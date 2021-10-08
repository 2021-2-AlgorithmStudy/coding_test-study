#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii; // size, color
int n, c, s;
vector<pii> v;        // size, color
vector<pii> origin_v; // size, color
// 각 사이즈 까지의 누적합 저장
unsigned int sum[2001];
// 색깔 별로 정렬된 사이즈와 그 누적합 저장(같은 색인 경우를 빼주기 위해)
vector<pii> color_minus[200001]; // size, 이때까지의 sum

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &c, &s);
        v.push_back(make_pair(s, c));
        origin_v.push_back(make_pair(s, c));
    }
    sort(v.begin(), v.end());
    int prev_num = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i].first != prev_num)
        {
            prev_num++;
            sum[prev_num] += sum[prev_num - 1];
        }
        sum[v[i].first] += v[i].first;
        color_minus[v[i].second].push_back(make_pair(v[i].first, color_minus[v[i].second].empty() ? v[i].first : v[i].first + color_minus[v[i].second].back().second));
    }
    int left, right;
    int mid, max_num, answer;
    for (int i = 0; i < origin_v.size(); i++)
    {
        max_num = -1;
        left = 0, right = color_minus[origin_v[i].second].size() - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (color_minus[origin_v[i].second][mid].first >= origin_v[i].first)
            {
                right = mid - 1;
            }
            // 현재와 사이즈가 같은 경우는 포함x, 총 합에서 같은 사이즈는 고려할 대상이 아님
            else if (color_minus[origin_v[i].second][mid].first < origin_v[i].first)
            {
                left = mid + 1;
                if (mid > max_num)
                    max_num = mid;
            }
        }
        // max_num 이 -1이다?
        // 배열이 비어서 같은 색인 걸 빼줄게 없는 경우, 아니면 현재 공의 사이즈보다 작은게 없어서 빼줄게 없는 경우이다.
        answer = sum[origin_v[i].first - 1] - (max_num == -1 ? 0 : color_minus[origin_v[i].second][max_num].second);
        printf("%d\n", answer < 0 ? 0 : answer);
    }

    return 0;
}