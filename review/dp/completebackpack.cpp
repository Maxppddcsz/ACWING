#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;
int n,m;
int v[N],w[N];
int f[N][N];

/*
f[i][j] 使用 i 种物品，容量为 j 的背包中物品的最大价值
f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
*/

int main(){
    cin>>n>>m;

    return 0;
}
