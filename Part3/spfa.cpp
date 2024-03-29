/*
    没有负环求最短路径
    queue <- 1
    while queue 不空
        1. t <- q front
           q pop
        2. 更新t的所有出边  t -w-> b
           queue <- b 队列里存放待更新的点

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

#define fi first
#define se second

typedef pair<int, int> PII; // 到源点的距离，下标号

int h[N], e[N], w[N], ne[N], idx = 0;
int dist[N]; // 各点到源点的距离
bool st[N];
int n, m;
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa()
{
    queue<PII> q;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push({0, 1});
    st[1] = true;
    while (q.size())
    {
        PII p = q.front();
        q.pop();
        int t = p.se;
        st[t] = false; // 从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                { // 当前已经加入队列的结点，无需再次加入队列，即便发生了更新也只用更新数值即可，重复添加降低效率
                    st[j] = true;
                    q.push({dist[j], j});
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int res = spfa();
    if (res == -1)
        puts("impossible");
    else
        printf("%d", res);

    return 0;
}
