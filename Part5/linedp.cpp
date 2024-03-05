/*
数字三角形:集合f(i,j),属性最大值,分为左上和右上两部分,(i,j)为行列坐标
涉及到i-1下标,从i=1开始
左边:f(i-1,j-1)+a[i,j] 右边:f(i-1,j)+a[i,j]
时间复杂度:状态数量*转移数量
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, INF = 1e9;
int n;
int a[N][N];
int f[N][N];
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            f[i][j] = -INF;

    f[1][1] = a[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
        }
    }

    int res = -INF;
    for (int i = 1; i <= n; i++)
        res = max(res, f[n][i]);

    cout << res << endl;
    return 0;
}
