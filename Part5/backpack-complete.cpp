/*
f[i-1,j]
f[i-1,j-k*v_i]+k*w_i
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];

// int f[N][N];
// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             for (int k = 0; k * v[i] <= j; k++)
//             {
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
//             }
//         }
//     }

//     cout << f[n][m] << endl;
//     return 0;
// }

/*
优化:转化为一维数组
f[i,j] = max(f[i-1,j],f[i-1,j-v]+w,f[i-1,j-2v]+2w,f[i-1,j-3v]+3w,...)
                                    |
                                    v
                                f[i,j-v]+w
f[i,j-v] = max(        f[i-1,j-v],  f[i-1,j-2v]+w, f[i-1,j-3v]+2w,...)
所以f[i,j] = max(f[i-1,j],f[i,j-v]+w)
*/
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}