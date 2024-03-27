#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    vector<vector<int>> res = {{-4,-2,6},{-4,0,4},{-4,1,3},{-4,2,2},{-2,-2,4},{-2,0,2},{-2,-2,4},{-2,0,2}};
    res.erase(unique(res.begin(), res.end()), res.end());
    
}