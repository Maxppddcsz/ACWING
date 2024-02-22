/*
n-皇后问题
dfs解决全排列问题
注意剪枝 提前停止
*/
#include <iostream>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];
// void dfs(int u)
// {
//     if (u == n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             puts(g[i]);
//         }
//         puts("");
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!col[i] && !dg[i+u] && !udg[i-u+n])
//         {
//             g[u][i] = 'Q';
//             col[i] = dg[i+u] = udg[i-u+n] = true;
//             dfs(u + 1);
//             col[i] = dg[i+u] =udg[i-u+n]= false;
//             g[u][i] = '.';
//         }
//     }
// }

void dfs(int x, int y, int s)
{
    // s代表摆了s个皇后
    if (y == n)
    {
        y = 0;
        x++;
    }

    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            puts(g[i]);
            puts("");
        }
        return;
    }

    // 不放皇后
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}