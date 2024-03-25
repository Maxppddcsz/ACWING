#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> PII;

const int N = 110;
int tt = -1, hh = 0, id;
char g[N][N];
PII q[N * N];

int w, h;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int visit[N][N];
const double eps = 1e-8;

void bfs(int a, int b)
{
    // printf("(%d,%d) ", a, b);
    // stars.push_back({a, b});
    q[++tt] = {a, b};
    visit[a][b] = 1;
    // g[a][b] = ch;
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < h && y >= 0 && y < w && !visit[x][y] && g[x][y] == '1')
            {
                visit[x][y] = 1;
                q[++tt] = {x, y};
            }
        }
    }
}

double get_hash()
{
    double sum = 0;
    for (int i = 0; i <= tt; i++)
    {
        for (int j = i + 1; j <= tt; j++)
        {
            double x_2 = (q[i].first - q[j].first) * (q[i].first - q[j].first);
            double y_2 = (q[i].second - q[j].second) * (q[i].second - q[j].second);
            sum += sqrt(x_2 + y_2);
        }
    }
    return sum;
}

char getc(double val)
{
    static double mp[30]; // static可认为是全局变量
    for (int i = 0; i < id; i++)
    {
        if (fabs(mp[i] - val) < eps)
        {
            return i + 'a';
        }
    }
    mp[id++] = val;
    return id - 1 + 'a';
}

int main()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        scanf("%s", g[i]);
    }

    // flood fill
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (g[i][j] == '1' && !visit[i][j])
            {
                tt = -1, hh = 0;
                // printf("%c:\n", ch);
                bfs(i, j);
                // printf("\n");
                // 相似 形状和数目相同 形状用每个点之间距离和作为哈希值表示
                char c = getc(get_hash());
                for (int k = 0; k <= tt; k++) // 所有入队的点的值更新为新的字符c
                {
                    g[q[k].first][q[k].second] = c;
                }
            }
        }
    }

    // printf("\n");
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         printf("%c", g[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < h; i++)
        cout << g[i] << endl;

    return 0;
}