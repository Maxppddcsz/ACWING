#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 1010;
typedef pair<int, int> PII;

int n, ans, flag;
vector<PII> points[N * N];
char g[N][N];
bool visit[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// void dfs(int a, int b, vector<PII> &points)
// {
//     printf("(%d,%d) ", a, b);
//     points.push_back({a, b});
//     // g[a][b] = '.';
//     visit[a][b] = 1;
//     for (int i = 0; i < 4; i++)
//     {
//         int x = a + dx[i], y = b + dy[i];
//         if (x >= 0 && y >= 0 && x < n && y < n && visit[x][y] == 0 && g[x][y] == '#')
//         {
//             dfs(x, y, points);
//         }
//     }
// }

void dfs(int a, int b)
{
    visit[a][b] = 1;
    if (g[a - 1][b] == '#' && g[a][b + 1] == '#' && g[a + 1][b] == '#' && g[a][b - 1] == '#')
    {
        flag = 1; // 上下左右都是陆地，不会淹没
    }
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (visit[x][y] == 0 && g[x][y] == '#')
        {
            dfs(x, y);
        }
    }
}

// void search(vector<PII> &points)
// {
//     int t;
//     int size = points.size();
//     for (auto item : points)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             int x = item.first + dx[i], y = item.second + dy[i];
//             if (x >= 0 && y >= 0 && x < n && y < n && g[x][y] == '.')
//             {
//                 // visit[x][y] = 1;
//                 // printf("(%d,%d) ", item.first, item.second);
//                 size--;
//                 break;
//             }
//         }
//     }
//     // printf("\n");
//     if (size > 0)
//     {
//         ans++;
//     }

//     // printf(" size: %d\n", size);
// }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", g[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == 0 && g[i][j] == '#')
            {
                flag = 0;
                // dfs(i, j, points[k++]);
                dfs(i, j);
                if (flag == 0)
                    ans++;
            }
        }
    }

    // printf("%d points\n", k);

    // for (int i = 0; i < k; i++)

    // {
    //     memset(visit, 0, sizeof visit);
    //     search(points[i]);
    // }

    printf("%d\n", ans);

    return 0;
}