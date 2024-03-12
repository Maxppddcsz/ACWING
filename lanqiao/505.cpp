/*
思路：离散化+归并排序

将a作为"参照系", 对b进行调整使其成为与a内部相对关系相同
a最高对b最高，a次高对b次高，a次次高对b次次高...
设置一个离散数组q 使得q[a[i]索引] = b[i]索引 使得 a 和 b 依次对应

若序列 a 与序列 b 相等，那么此时 q[a[i]索引] 应该等于 a[i]索引 的，也就是q[i]=i
也就是说如果我们想让序列 a 与序列 b 相等，那么我们需要让 q 升序排列
问题就变为：将原本乱的 q 序列升序排列的最少交换次数
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 99999997
const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n;
PII a[N], b[N];

int q[N], tmp[N];
int res;

void merge_sort(int a[], int l, int r)
{
    int mid = l + r >> 1;

    int i = l, j = mid + 1, k = 0;

    // printf("l: %d, r: %d, mid: %d\n", l, r, mid);

    if (l >= r)
        return;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            res += mid - i + 1;
            res %= 99999997;
        }
    }

    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }

    while (j <= r)
    {
        tmp[k++] = a[j++];
    }

    for (int i = l, j = 0; i <= r; i++, j++)
    {
        a[i] = tmp[j];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < n; i++)
    {
        q[a[i].second] = b[i].second;
        // printf("%d %d\n", a[i].second, b[i].second);
    }

    merge_sort(q, 0, n - 1);

    printf("%lld\n", res);
    return 0;
}