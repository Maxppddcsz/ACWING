/*
1. 将所有区间按左端点从小到大排序
2. 从前往后依次枚举每个区间，在所有能覆盖 start 区间中选择一个右端点最大的区间，然后将 start 更新成右端点的最大值
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(const Range &W) const
    {
        return l < W.l;
    }
} range[N];

int n, res;

bool success = false;

int main()
{
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    sort(range, range + n);
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -1e9;
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j++;
        }

        if (st > r)
        {
            res = -1;
            break;
        }

        res++;
        if (ed <= r)
        {
            success = true;
            break;
        }
        st = r;
        i = j - 1;
    }

    if (!success)
        res = -1;
    printf("%d\n", res);
    return 0;
}