/*
Trie：快速存储查找字符串集合
形式：字典形式,在树中每一个字符串结尾写一个标记(cnt[])
abcdef
abdef
*/
#include<iostream>
using namespace std;
const int N = 10010;
int son[N][26], cnt[N], index;
void insert(char str[]){
    int p = 0;
    for (int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++index;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char str[]){
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
