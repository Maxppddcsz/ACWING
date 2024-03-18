/*
按照wi+si从小到大的顺序排，最大的危险系数一定最小
贪心得到的答案>=最优解
贪心得到的答案<=最优解
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 50010;
int n;
PII cow[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s, w;
        scanf("%d%d", &w, &s);
        cow[i] = {w + s, w};
    }

    sort(cow, cow + n);
    int res = -2e9, sum = 0;

    for (int i = 0; i < n; i++)
    {
        int w = cow[i].second;
        int s = cow[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }

    printf("%d\n", res);
    return 0;
}