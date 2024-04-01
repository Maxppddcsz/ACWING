#include<iostream>
#include<cmath>
using namespace std;
int n;
bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2;i <= n / i;i ++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(is_prime(x)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}