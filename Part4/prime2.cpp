#include<iostream>
#include<algorithm>
#include<vector>
/*
n中最多只含有一个大于sqrt(n)的因子。证明通过反证法：如果有两个大于sqrt(n)的因子，那么相乘会大于n，矛盾。证毕
于是我们发现最多只有一个大于sqrt(n)的因子，对其进行优化。先考虑比sqrt(n)小的，代码和质数的判定类似
最后如果n还是>1，说明这就是大于sqrt(n)的唯一质因子，输出即可。
*/
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        for(int i=2;i<=x/i;i++){
            int e = 0,flag = 0;
            if(x%i==0){
                while(x%i==0){
                    flag = 1;
                    e++;
                    x/=i;
                }
                printf("%d %d\n",i,e);
            }       
        }
        if(x>1) printf("%d 1\n",x,1);
        printf("\n");
    }
    return 0;
}