/*
与选择点的那道题一模一样
*/

/*
1. 将每个区间右端点从小到大排序
2. 从前往后依次枚举每个区间，如果当前区间已经包含点，pass，否则选择当前区间右端点
贪心：每次都在当前最小块里选择局部最优解
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l, r;
    bool operator<(const Range &w) const
    {
        return r < w.r;
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

    int res, ed = -2e9;

    for (int i = 0; i < n; i++)
    {
        if (range[i].l > ed)
        {
            res++;
            ed = range[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}