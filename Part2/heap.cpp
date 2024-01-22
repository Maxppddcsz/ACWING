/*
堆：完全二叉树：除了最后一层节点外上面所有节点都是非空的
小根堆：每个点都小于左右节点从->根节点为最小值
点x，左son 2x，右son 2x+1
down；up 节点上移/下移
插入一个数：heap[++size] = x; up(size)
求当前集合中最小值: heap[1];
删除最小值: heap[1] = heap[size]; size--; down(1);
删除任意一个元素: heap[k] = heap[size]; size--; down(k); up(k);
修改任意一个元素: heap[k] = x; down(k); up(k);
*/
#include <iostream>
using namespace std;

const int N = 100010;
int h[N];
int size, n, m;
void down(int u)
{
    int t = u;
    if (2 * u <= size && h[2 * u] < h[u])
        t = 2 * u;
    if (2 * u + 1 <= size && h[2 * u + 1] < h[u])
        t = 2 * u + 1;
    if(u!=t){
        swap(u, t);
        down(t);
    }
}
void up(int u){
    while(u/2 && h[u/2] > h[u]){
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i; i < n; i++)
        scanf("%d", &h[i]);
    size = n;
    for (int i = n / 2; i; i--)
        down(i);
    return 0;
}