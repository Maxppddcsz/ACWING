/*
树是一种特殊的图
有向图：邻接矩阵 g[a,b] 邻接表 单链表
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10; // 数据范围是10的5次方
const int M = 2 * N;    // 以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

int idx = 0;
int h[N], e[M], ne[M];
int n, m;
int st[N];

int ans = N;
// 邻接表
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 返回以u为根的子树中点的数量
int dfs(int u)
{
    int sum = 1, res = 0;
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}