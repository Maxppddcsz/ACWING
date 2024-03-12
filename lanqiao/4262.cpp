// 原问题等价于将差分数组 b 全部变为 0 的最少次数
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int p[N];
int t[N];
int b[N];
int k[N];
int n;

void insert(int l, int r)
{
    b[l] += 1;
    b[r + 1] -= 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        k[i] = p[i] - t[i];
        b[i] = k[i] - k[i - 1];
    }

    int s = 0, t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > 0)
            s += b[i];
        else if (b[i] < 0)
            t -= b[i];
    }

    printf("%d\n", max(s, t));

    return 0;
}