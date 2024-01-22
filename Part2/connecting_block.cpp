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

int p[N],size[N];

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
        size[i] = 1;
    }
    while (m--)
    {
        char op[2];
        scanf("%s",op);
        if (op[0] == 'C')
        {
            scanf("%d%d",&a, &b);
            if(find(a)==find(b)) continue;
            size[find(b)] += size[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            scanf("%d", &a);
            printf("%d", size[find(a)]);
        }
    }
    return 0;
}
