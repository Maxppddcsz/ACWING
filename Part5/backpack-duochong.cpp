#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N], s[N];
// int f[N][N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i] >> s[i];

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             for (int k = 0; k * v[i] <= j && k < s[i]; k++)
//             {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
//             }
//         }
//     }

//     cout << f[n][m] << endl;
//     return 0;
// }

// 优化：二进制优化 将s个物品划分为logs组
/*
优化
f[i,j] =   max(f[i-1,j],f[i-1,j-v]+w,f[i-1,j-2v]+2w,...,f[i-1,j-sv]+sw    )
f[i,j-v] = max(         f[i-1,j-v],  f[i-1,j-2v]+w,..., f[i-1,j-sv]+(s-1)w,f[i-1,j-(s+1)v]+sw)
*/
int f[N];

int main()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[j]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
}