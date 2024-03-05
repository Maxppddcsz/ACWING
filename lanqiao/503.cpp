#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;
int n, m;
int d[N], r[N];
int s[N], t[N];

// int main()
// {
//     scanf("%lld%lld", &n, &m);
//     for (int i = 1; i <= n; i++)
//         cin >> r[i];
//     for (int i = 1; i <= m; i++)
//     {
//         int s, t;
//         cin >> d[i] >> s >> t;
//         for (int j = s; j <= t; j++)
//         {
//             r[j] -= d[i];
//             if (r[j] < 0)
//             {
//                 printf("-1\n%d", i);
//                 return 0;
//             }
//         }
//     }
//     printf("0\n");
//     return 0;
// }

// 空间非常大,使用差分来解决问题

long long b[N], ba[N];

bool check(int mid)
{
    long long a;
    for (int i = 1; i <= n; i++)
        ba[i] = b[i];
    for (int i = 1; i <= mid; i++)
    {
        ba[s[i]] -= d[i]; // 差分基本操作
        ba[t[i] + 1] += d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        a += b[i];
        if (a < 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r[i]);
        // add(r[i], i, i);
        b[i] = r[i] - r[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
    }

    if (check(m))
    {
        printf("0\n");
    }
    else
    {
        int l = 1, r = m;

        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) // mid<0
            {
                l = mid + 1;
            }
            else // mid>=0
            {
                r = mid;
            }
        }
        printf("-1\n&d", l);
    }

    return 0;
}
