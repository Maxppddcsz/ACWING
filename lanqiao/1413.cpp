#include <iostream>
#include <algorithm>

using namespace std;
const int N = 3010;

int m, n, p;
int l[N], r[N];
int stk[N];
int g[N][N], h[N][N];

int work(int h[])
{

    h[0] = h[n + 1] = -1;
    int top = 0;

    stk[++top] = 0;
    for (int i = 1; i <= n; i++)
    {
        // 对于每块格子，确保栈顶元素的格子高度小于当前元素格子高度
        while (h[stk[top]] >= h[i])
        {
            top--;
        }
        // 保存格子i左边第一个高度小于格子i的格子的下标
        l[i] = stk[top];
        stk[++top] = i;
    }
    top = 0;
    stk[++top] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        while (h[stk[top]] >= h[i])
        {
            top--;
        }
        r[i] = stk[top];
        stk[++top] = i;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, h[i] * (r[i] - l[i] - 1));
    }
    return res;
}

int main()
{
    scanf("%d%d%d", &m, &n, &p);
    while (p--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!g[i][j])
            {
                h[i][j] = h[i - 1][j] + 1;
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= m; i++)
    {
        res = max(res, work(h[i]));
    }
    printf("%d\n", res);

    return 0;
}