#include<iostream>
#include<algorithm>

using namespace std;

/*
状态表示：f[i,j] i堆石子到j堆石子合并成一堆石子的合并方式，代价的最小值
状态计算：以最后一次分界线的位置分类 f[i,k]+f[k+1,j]+s[j]-s[i-1](前缀和)
*/

const int N = 310;
int n;
int s[N];
int f[N][N];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;
            for(int k=1;k<r;k++){
                f[l][r] = 2e9;
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }   
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}