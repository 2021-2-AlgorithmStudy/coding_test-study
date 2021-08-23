#include <cstdio>
#include <vector>
using namespace std;
int n, num;
vector<int> v;
int search_upper_bound(int num)
{
    int mid, left = 0, right = v.size() - 1, result = 1000002;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid] == num)
            return mid;
        else if (v[mid] < num)
            left = mid + 1;
        else if (v[mid] > num)
        {
            if (result > mid)
                result = mid;
            right = mid - 1;
        }
    }
    return result;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (v.empty())
        {
            v.push_back(num);
            continue;
        }
        if (num > v.back())
            v.push_back(num);
        else
            v[search_upper_bound(num)] = num;
    }
    printf("%lu", v.size());
    return 0;
}