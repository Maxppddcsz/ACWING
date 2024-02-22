/*
宽度优先：队列 最短路径
走迷宫问题
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];
typedef pair<int, int> PII;
PII q[N * N];
int dfs()
{

    int tt = 0, hh = 0;
    int x, y;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    q[0] = {0, 0};

    while (hh <= tt)
    {
        auto t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            x = t.first + dx[i];
            y = t.second + dy[i];
            if (g[x][y] == 0 && x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << dfs() << endl;
    return 0;
}