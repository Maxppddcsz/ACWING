/*
离散的时候为了防止重复，使用pair<数值,索引>的形式
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

PII h[N], tmp[N];
int n, sw, ans;
int num[N], st[N];

void merge_sort(int l, int r)
{

    if (l >= r)
        return;
    // printf("l: %d, r: %d\n", l, r);
    int mid = l + r >> 1, i = l, j = mid + 1, k = 0;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    while (i <= mid && j <= r)
    {

        if (h[i].second <= h[j].second)
        {
            tmp[k++] = h[i++];
        }
        else
        {
            // printf("swap %d and %d\n", h[i].second, h[j].second);

            for (int p = i; p <= mid; p++)
            {
                num[h[p].first]++;
                // st[h[p].first] = num[h[p].first] * (num[h[p].first] + 1) / 2;
                //  printf("st[%d]-> %d : %d\n", h[p].first, h[p].second, st[h[p].first]);

                num[h[j].first]++;
                // st[h[j].first] = num[h[j].first] * (num[h[j].first] + 1) / 2;
                //  printf("st[%d]-> %d : %d\n", h[j].first, h[p].second, st[h[j].first]);
            }

            tmp[k++] = h[j++];
        }
    }

    while (i <= mid)
    {
        tmp[k++] = h[i++];
    }

    while (j <= r)
    {
        tmp[k++] = h[j++];
    }

    for (int i = l, j = 0; i <= r; i++, j++)
    {
        h[i] = tmp[j];
        // printf("%d ", h[i].second);
    }
    // printf("\n");
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        h[i].first = i;
        scanf("%d", &h[i].second);
    }

    merge_sort(0, n - 1);

    for (int i = 0; i <= N; i++)
    {
        // ans += st[i];
        ans += num[i] * (num[i] + 1) / 2;
    }

    printf("%d\n", ans);

    return 0;
}