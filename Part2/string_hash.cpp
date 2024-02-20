/*
字符串前缀哈希法
1. 预处理所有前缀的哈希 h[0],h[1]...
p=131/1331
Q=2^64
将字符串转换为p进制的数字 mod Q
h(i) = h(i-1)*P + str[i]
h[l~r]  = h[r] - h[l-1]*P^(r-l+1)

用处：字符串中某两段是否相同
 */

#include <iostream>
using namespace std;
const int N = 100010, P = 1331;
typedef unsigned long long ULL;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int l1, r1, l2, r2;

    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m--)
    {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}