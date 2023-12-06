#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int m, n;
int s[N], a[N];
int main()
{
    int l, r;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}