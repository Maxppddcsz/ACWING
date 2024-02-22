/*
若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前
则称 A 是该图的一个拓扑序列 -> 有向无环图 至少存在一个入度为 0 的点

1. 入度为0的点可以作为起点 -> 入度为0的点入队
2. while queue 不空
    {
        t <- 队头
        t所有出边k
            删除 t-j d[j]--;
            if(d[i] ==0) j入队
    }
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100010;

int idx, m, n;
int h[N], e[N], ne[N];
int d[N], q[N]; // d[i] i的入度

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (!d[i])
            q[++t] = i;
    }

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[t])
        {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
            {
                q[++tt] = j;
            }
        }
    }
    return tt == (n - 1);
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add(a, b);
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++)
            printf("%d  ", q[i]);
        puts("");
    }
    else
        puts("-1");
    return 0;
}
