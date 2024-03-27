#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n,m;
char a[N],b[N];
int f[N][N];

/*
集合：所有将a[1-i]变成b[1-j]的方式
f[i][j] 匹配 a[1-i]和b[1-j]
一个字符串可能由删除/插入/替换而来
删 f[i-1][j] + 1
增 f[i][j-1] + 1
改 f[i-1][j-1] + 1/0
f[i][j] = min(,,)
*/

int main(){

    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%d",&m);
    scanf("%s",b+1);

    for(int i=0;i<=m;i++){
        f[0][i] = i;
    }

    for(int i=0;i<=n;i++){
        f[i][0] = i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j] = min(f[i-1][j] + 1,f[i][j-1] + 1);
            if(a[i] == b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1]+1);
        }
    }

    cout<<f[n][m];
    
    return 0;
}