/*
边权负数
for n:
    for 所有边 a,b,w a--w--> b
        dist[b] = min(dist[b],dist[a]+w);
dist[b] <= dist[a]+w)
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int backup[N], dist[N];

struct Edge
{
    int a, b, w;
} edge[M];

int bellman_ford()
{
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[i].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{

    scanf("%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }

    int t = bellman_ford();
    printf("%d\n", t);

    return 0;
}