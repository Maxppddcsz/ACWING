#include <iostream>
#include <algorithm>

using namespace std;
const int N = 200;
int n, cnt = 0;
const int eps = 1e-6;

struct Number
{
    int t, d;
    double v;
} num[N];

bool cmp(Number a, Number b)
{
    return b.v - a.v > eps;
}

int main()
{
    scanf("%d", &n);

    num[0].t = 0, num[0].d = 1, num[0].v = 0.0;
    cnt++;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            double tmp = (double)j / i;
            bool st = false;
            for (int k = 1; k <= cnt; k++)
            {
                if (tmp == num[k].v)
                {
                    st = true;
                    break;
                }
            }
            if (!st)
            {
                num[cnt].d = i, num[cnt].t = j, num[cnt].v = tmp;
                cnt++;
            }
        }
    }
    num[cnt].t = 1, num[cnt].d = 1, num[cnt].v = 1.0;
    sort(num, num + cnt, cmp);
    for (int i = 0; i <= cnt; i++)
        printf("%d/%d\n", num[i].t, num[i].d);
    return 0;
}