/*
1. 01背包：每件物品最多只用一次 N件物品 V容量
2. 完全背包：每件物品无限次使用
3. 多重背包：每个物品个数不一样 -> 优化
4. 分组背包：每组里可以使用N个物品

DP: y优化是对方程进行等价变形
1. 状态表示 f(i,j)
    a. 集合：
        i. 所有选法
        ii. 条件：只从前i个物品中选，总体积<=j
    b. 属性：最大值*(背包问题)，最小值，数量
2. 状态计算 集合划分
    f(i,j) = MAX(f(i-1,j),f(i-1,j-vi)+wi)


*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int v[N], w[N];
int f[N][N];

const int N = 1010, M = 1010;

// 二维
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

/*
优化:转化为一维数组 f(i)只用到了f(i-1)
int f[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

*/