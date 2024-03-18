/*
从小到大的顺序排序，等待时间最小
T = t1(n-1)+t2(n-2)+t3(n-3)+...
证明：调整法，找到 ti>ti+1，交换位置后 T 变小，因此可证
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010;
int n;
int t[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    sort(t, t + n);

    LL res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (n - i - 1) * t[i];
    }
    printf("%lld\n", res);

    return 0;
}