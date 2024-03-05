/*
状态表示:集合:所有以第i个数结尾的上升子序列;属性:集合里面每个上升子序列长度的最大值
状态计算:以i-1分类:为a[0],a[1],..a[i-1] f_i = max(f[j]+1) a_j<a_i a=0,..,i-1

动态规划分类的标准***
*/
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;
int a[N], f[N], g[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);

    printf("%d\n", res);
    return 0;
}