/*
拉链法：a mod 10^5
0 1 2 3 4  ... 10^5-1
      |
      11
      |
      23
      ...
 */
#include <iostream>
#include <string.h>
using namespace std;

const int N = 10003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

int find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[k])
        if (ne[i] == x)
            return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (op[0] == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}