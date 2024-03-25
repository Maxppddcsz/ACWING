#include <iostream>
#include <stdlib.h>
using namespace std;

/*
滑动窗口：单调队列
只要队列里存在ax<=ay,x>y,就删掉前面的,获得单调

窗口里极值 离元素最近/最大的数
*/
const int N = 1e6 + 10;

int a[N], q[N];

int main()
{
    int n, k;
    cin >> n >> k;

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    printf("\n");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    return 0;
}