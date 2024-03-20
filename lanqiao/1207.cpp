// 点数和边数差别不大时就是稀疏图
// 稀疏图 ： —— 邻接表
// 稠密图 ： —— 邻接矩阵(两重循环)

/*
定义：树上最远的两个节点之间的距离就被称为树的直径
构造方法：任意在树上取一个点P，找出离这个点最远的另一个点A，再找出离A最远的点（记为B）的距离就是树的直径。
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1000010;

int h[N], e[N], ne[N], w[N];
int n, idx, maxu, maxd;
LL res;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int fa, int d)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j, k;
        j = e[i];
        k = w[i];
        if (j == fa)
            continue;
        if (d + k > maxd)
        {
            maxd = d + k;
            maxu = j;
        }
        dfs(j, u, d + k);
    }
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int p, q, d;
        scanf("%d%d%d", &p, &q, &d);
        add(p, q, d);
        add(q, p, d);
    }

    // 随便选一个点1，找到距离它最远的点 maxu
    dfs(1, -1, 0);
    // 找到距离 maxu 最远的点，它们之间的距离就是树的直径
    dfs(maxu, -1, 0);

    // printf("%d\n", maxd);

    res = maxd * 10 + (LL)(maxd + 1) * maxd / 2; // LONGLONG!!

    printf("%lld\n", res);
    return 0;
}