/*
1. 单链表：邻接表 -> 存储图和树
2. 双链表 -> 优化问题

e[N](本结点数值) ne[N](下一个节点下标)
head(头节点) idx(当前已经用到哪个节点)
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int head, e[N], ne[N];
int l[N], r[N];

int idx;

void init()
{
    head = -1, idx = 1;
}

void add_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void insert(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove(int k)
{
    if (k == 0)
        head = ne[head];
    ne[k] = ne[ne[k]];
}

int main()
{
    int n, x, k;
    cin >> n;

    init();

    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'H')
        {

            cin >> x;
            add_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            remove(k);
        }
        else
        {
            cin >> k >> x;
            insert(k, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}
