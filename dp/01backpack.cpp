#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;
int v[N],w[N];
int n,m;
/*
dp[i][j]: 使用前i个物品，体积为j的最大价值
dp[i][j] = dp[i - 1][j];
if (j >= v[i]) // 从第 1 ~ i-1中选，且总体积不超过 j-v[i]
    dp[i][j] = max(dp[i-1][j-v[i]]+w[i],dp[i][j])
*/

int main(){
    cin>>n>>m;

    return 0;
}