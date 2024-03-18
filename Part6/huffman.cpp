/*
每次挑出最小的两个堆合并

*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010;
int n;
int main()
{
    priority_queue<int, vector<int>, greater<int>> heap;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        heap.push(x);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int a, b;
        a = heap.top();
        heap.pop();
        b = heap.top();
        heap.pop();
        res += a + b;
        heap.push(a + b);
    }

    printf("%d\n", res);
    return 0;
}