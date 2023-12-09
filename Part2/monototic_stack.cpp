/*
找到左边最近且比元素小的元素位置：
1. ax>=ay,a<=y,则删除ax
2. 剩下为单调栈
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int st[N], tt = 0;

int main()
{
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;
        while (tt && st[tt] >= x)
            tt--;
        if (tt == 0)
            cout << -1 << ' ';
        else
            cout << st[tt] << ' ';
        st[++tt] = x;
    }

    return 0;
}