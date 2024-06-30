#include<iostream>
/*
诶氏筛法 O(nloglogn)
void get_primes1(){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
            for(int j=i;j<=n;j+=i) st[j]=true;//可以用质数就把所有的合数都筛掉；
        }
    }
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

//primes数组用来存放质数
int primes[N], cnt;
//st[i], i为质数则为false否则为true
bool st[N];

void get_primes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        //假设primes[0]为n最小的质因子,i为最大的因数，
        //易知若primes[i]中i>0,则会进入循环后产生多余的标记。
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            //标记;primes[j]一定是primes[j]*i的最小质因子
            st[primes[j]*i] = true;
            //表明primes[j]一定是i的最小质因子,没有必要再遍历,primes要小于等于i的最小质因子
            //这样能保证每个数遍历一遍,而没有重复
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    return 0;
}