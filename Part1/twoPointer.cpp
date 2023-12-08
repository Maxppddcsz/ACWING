#include <iostream>
#include <string.h>
using namespace std;
/*
双指针:
1.指向一个序列（快排）
2.指向两个序列（归并）

for(int i=0;i<n;i++){
    while(j<i && check(i,j)) j++;
    //每道题目具体逻辑
}

核心思想：优化 O(n)
可以从暴力解法开始想
找到一些单调性
*/

const int N = 1e6 + 10;
int a[N];
int S[N];
int main()
{
    // A + B 问题
    // char str[1000000];
    // gets(str);
    // int n = strlen(str);

    // for (size_t i = 0; i < n; i++)
    // {
    //     int j = i;
    //     while (j < n && str[j] != ' ')
    //         j++;
    //     for (size_t k = i; k < j; k++)
    //     {
    //         printf("%c", str[k]);
    //     }
    //     printf("\n");
    //     i = j;
    // }

    // 最长连续不重复子序列
    // int n, res;
    // res = 0;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &a[i]);

    // for (int i = 0, j = 0; i < n; i++)
    // {
    //     S[a[i]]++;
    //     while (S[a[i]] > 1)
    //     {
    //         S[a[j]]--;
    //         j++;
    //     }
    //     res = max(res, i - j + 1);
    // }
    // printf("%d\n", res);

    return 0;
}