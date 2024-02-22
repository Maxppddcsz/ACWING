/*
深度优先：栈 空间少
*/
// 数字排列问题
#include <iostream>
using namespace std;
const int N = 7;
int n;
bool st[N];
int path[N];
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << path[i] << ' ';
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (st[i] == false)
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}