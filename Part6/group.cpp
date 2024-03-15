/*
1. 将所有区间左端点从小到大排序
2. 从前往后处理每个区间，判断能否将其放到某个现有的组中 -> L[i] > Max_r
   1. 不存在这样的组，开新组，将其放入
   2. 如果存在，将其放入组，更新当前组的 Max_r
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 100010;
int n;
struct Range
{
    int l, r;
    bool operator<(const Range &W) const
    {
        return this->l < W.l;
    }
} range[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++)
    {
        auto r = range[i];
        if (heap.empty() || heap.top() >= r.l)
        {
            heap.push(r.r);
        }
        else
        {
            heap.pop();
            heap.push(r.r);
        }
    }
    printf("%d\n", heap.size());

    return 0;
}