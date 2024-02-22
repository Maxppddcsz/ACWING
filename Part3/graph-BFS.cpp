#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
const int M = 2 * N;
int idx, m, n;
int h[N], e[M], ne[M];
int d[N], q[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(int u)
{
    int tt, hh;
    q[0] = 1;
    memset(d, -1, sizeof d);

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[t])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
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
    cout << bfs(1) << endl;
    return 0;
}