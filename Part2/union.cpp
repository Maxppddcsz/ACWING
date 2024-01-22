/*
    并查集：1. 将两个集合合并；2. 询问两个元素是否在一个集合中
    集合编号是根节点元素，每个节点存储其father -> 根据节点father递归查找每个元素属于哪个集合
    判断树根：p[x] == x
    求x的集合编号：while(p[x]!=x) x=p[x]
    合并两个集合：将一个集合插到另一个集合 p[x] = y
*/
#include <iostream>
using namespace std;
const int N = 100010;

int p[N];

int find(int x)
{
    if (!p[x] == x)
        find(p[x]);
    return p[x];
}

int main()
{
    int m, n;
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    while (m--)
    {
        char op[2];
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M')
        {
            p[find(a)] = find(b);
        }
        else
        {
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
