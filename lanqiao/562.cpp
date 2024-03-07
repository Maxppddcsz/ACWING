#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5000010;

int t, n[N];
char s[N];
int res[N];

void prefix(int id, int n, char *str)
{
    int score = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = str[i] - '0';
        res[i] = res[i - 1] + tmp;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", res[i]);
    // }
    // printf("\n");

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         int len;

    //         if (n % 2 == 1)
    //             len = n / 2 + 1;
    //         else
    //             len = n / 2;

    //         if ((j - i) + 1 <= len && j >= i)
    //         {

    //             score = max(score, res[j] - res[i - 1]);
    //             // printf("%d %d %d %d\n", i, j, res[j] - res[i - 1], score);
    //         }
    //     }
    // }
    int len;
    if (n % 2 == 1)
        len = n / 2 + 1;
    else
        len = n / 2;

    for (int i = len; i <= n; i++)
    {
        score = max(score, res[i] - res[i - len]);
    }

    printf("Case #%d: %d\n", id, score);
}

int main()
{
    cin >> t;
    memset(s, '0', sizeof s);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d%s", &n[i], (s + 1));
        // printf("%d\n%s\n", n[i], s + 1);
        prefix(i, n[i], s);
    }

    return 0;
}