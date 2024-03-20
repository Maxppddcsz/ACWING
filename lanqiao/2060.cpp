/*
搜索连通块：flood fill (1) dfs 可能栈溢出 (2) bfs 可求最短路
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
const int N = 55;

char g[N][N];
vector<PII> points[2];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, m;

void dfs(int a, int b, vector<PII> &points)
{
    points.push_back({a, b});
    g[a][b] = '.';
    for (int i = 0; i < 4; i++)
    {

        int x = a + dx[i], y = b + dy[i];
        if (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 'X')
        {
            dfs(x, y, points);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", g[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'X')
            {
                dfs(i, j, points[k++]);
            }
        }
    }

    // for (auto &a : points[0])
    // {
    //     printf("(%d,%d) ", a.first, a.second);
    // }
    // printf("\n");

    // for (auto &a : points[1])
    // {
    //     printf("(%d,%d) ", a.first, a.second);
    // }
    // printf("\n");

    int dst = 110;
    for (auto &a : points[0])
    {
        for (auto &b : points[1])

        {
            dst = min(dst, abs(a.first - b.first) + abs(a.second - b.second));
        }
    }

    printf("%d\n", dst - 1);
    return 0;
}