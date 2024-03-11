#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int k, n;
int a[N];
int s[N];
int res;

int main()
{

    scanf("%d%d", &n, &k);

    memset(a, 0, sizeof a);
    memset(s, 0, sizeof s);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            // printf("%d~%d: %d\n", i, j, s[j] - s[i - 1]);
            if ((s[j] - s[i - 1]) % k == 0)
                res++;
        }
    }

    printf("%d\n", res);
    return 0;
}