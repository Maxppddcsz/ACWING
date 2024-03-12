#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, len;
int s[N], l[N];
int st[N];
bool check(int t)
{
    int sum = 0;

    for (int i = 0; i <= len + 1; i++)
    {
        st[i] = 0;
    }
    // printf("t: %d\n", t);
    for (int i = 1; i <= n; i++)
    {
        // printf("s[%d] =  %d, ", i, s[i]);
        //     l[i]-(t-s[i]) & l[i]+(t-s[i]) 置零
        if (s[i] <= t)
        {
            int begin = max(1, l[i] - (t - s[i]));
            int end = min(len, l[i] + (t - s[i]));
            // printf("begin: %d , end: %d\n", begin, end);
            for (int j = begin; j <= end; j++)
            {
                st[j] = 1;
            }
        }
    }

    for (int i = 1; i <= len; i++)
    {
        if (st[i] == 1)
        {
            sum++;
        }
        // else
        // {
        //     printf("no.%d empty\n", i);
        // }
    }

    // printf("sum: %d\n\n", sum);
    if (sum < len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d%d", &n, &len);

    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> s[i];
    }

    int left = 1;
    int right = 1e9;
    // 1,mid mid+1,r
    while (left < right)
    {

        int mid = (left + right) >> 1;
        printf("%d %d %d\n", left, right, mid);
        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    printf("%d\n", left);
    return 0;
}