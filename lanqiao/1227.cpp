#include <iostream>
#include <algorithm>
using namespace std;

/*
    边长 a 1~100000
    总共 sum(min( h[i]/a , w[i]/a )) >= k
*/

const int N = 100010;
int n, k;
int h[N], w[N];
int l, r, mid;

bool check(int a)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // printf("h: %d, w: %d, edge: %d\n", h[i] / a, w[i] / a, min(h[i] / a, w[i] / a));
        sum += (h[i] / a) * (w[i] / a);
    }

    // printf("edge: %d,sum: %d\n", a, sum);
    if (sum >= k)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &h[i], &w[i]);
    }

    l = 1;
    r = 10;

    while (l < r)
    {
        mid = (l + r) + 1 >> 1;
        // printf("%d %d %d\n", l, r, mid);
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    // printf("%d", r);
    return 0;
}