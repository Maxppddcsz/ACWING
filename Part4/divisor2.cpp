/*
12 可以分解为：2^2*3^1。所以2可以取 0 ~ 2个，3种取法。3可以取 0~1 个，2种取法。12的约数一共：2 * 3 = 6个。
也就是：把一个数N 写成：N = (p1^x1^)(p^x2)(p3^x3)…(pk^xk)，其中pi为质数。则N的约数个数为：(x1+1)(x2+1)(x3+1)…(xk+1)
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int mod = 1e9+7 ;
int main()
{
    int T; 
    cin >> T;
    unordered_map<int, int> h;
    while(T--)
    {
        int n; cin >> n;
        //依次求出指数
        for(int i = 2; i <= n / i; i++)
        {
            while(n % i == 0)
            {
                //指数+1
                h[i] ++;
                n = n / i;
            }
        }
        //如果有剩余，也是一个质因子
        if(n > 1) h[n]++;
    }

    long long  res = 1;
    for(auto iter = h.begin(); iter != h.end(); iter++)
    {
        //res = (x1+1)(x2+1)(x3+1)…(xk+1)
        res = res * (iter->second + 1) % mod ;
    }
    cout << res;
}