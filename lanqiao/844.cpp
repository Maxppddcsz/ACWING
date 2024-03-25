#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];
typedef pair<int, int> PII;
PII q[N * N];

int bfs()
{
    int hh = 0, tt = 0;
    int x, y;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

    memset(d, -1, sizeof d);

    d[1][1] = 0;
    q[0] = {1, 1};
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 1 && y >= 1 && x <= n && y <= m && g[x][y] == 0 && d[x][y] == -1)
            {

                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }
    return d[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}