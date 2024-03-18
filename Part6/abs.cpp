#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
int d[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    sort(d, d + n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += abs(d[i] - d[n / 2]);
    }
    printf("%d\n", res);

    return 0;
}