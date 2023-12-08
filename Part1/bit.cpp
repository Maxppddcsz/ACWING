/*
n的二进制表示中第k位是几？
1.先把第k位移到最后1位 -> n>>k
2. 看个位是几

lowbit(x):返回x最后一位是1的二进制数 = x&(~x+1)
lowbit(11000) = 1000
可用于求二进制中1的个数
*/
#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & (~x + 1);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        int res = 0;
        cin >> x;
        while (x)
            x -= lowbit(x), res++;
        cout << res << ' ';
    }
    return 0;
}