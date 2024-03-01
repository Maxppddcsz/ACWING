/*
    优化思路:如果转移时使用上一层状态,从大到小枚举体积;如果使用本层状态,从小到大枚举体积
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int v[N][N], w[N][N];
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < s[i]; k++)
            {
                if (v[i][k] <= j)
                {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << endl;
    return 0;
}
