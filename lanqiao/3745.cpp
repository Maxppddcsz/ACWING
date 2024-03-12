#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int c[N];

int main()
{
    int n, L, temp;
    cin >> n >> L;
    temp = n - 1;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c + 1, c + n + 1, greater<int>()); // 从大到小排序：100 3 2 1
    for (int i = n; i >= 1; i--)
    { // 寻找补1可以提高h指数的位置
        if (c[i] >= i)
        { // i==3时，c[i]==2 此时c[i]+1，则h指数可以提高
            temp = i;
            break;
        }
    }
    for (int i = temp + 1; i >= 1; i--)
    { // 应当把1往大引用量加：即若有多余的L，应当：101 4 3 1。因为目标是通过分界处i和c[i]的调和，来使得h指数提高
        if (L)
        {
            c[i]++;
            L--;
        }
    }
    sort(c + 1, c + n + 1, greater<int>()); // 写完综述，论文的引用情况
    for (int i = n; i >= 1; i--)
    { // 100 3 3 1
        // 有i篇引用次数>=c[i]：有4篇引用次数>=1    有3篇引用次数>=3    有2篇引用次数>=3    有1篇引用次数>=100
        if (c[i] >= i)
        { // 100 3 2 1的情况：c[2]>=2时退出，即有2篇>=2但实际上有3篇>=2(至少h篇引用次数不少于h)
            cout << i;
            return 0;
        }
    }
    cout << 0; // 引用量全为0
    return 0;
}