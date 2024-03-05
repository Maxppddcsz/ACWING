/*
状态表示：集合：所有在第一个序列的前i个字母出现，且在第二个序列的前j个字母中出现的公共子序列；属性：Max
状态计算：包含/不包含 a[i]/b[j] => f[i-1,j-1] f[i-1,j] f[i,j-1] f[i-1,j-1]+1 相互可以重叠(求数量不可以重复)

*/
#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

using namespace std;

int main()
{
    cin >> n >> m;
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}