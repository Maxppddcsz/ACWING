#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 10010;
int l, m;
vector<PII> segs, res;

int main()
{
    scanf("%d%d", &l, &m);

    for (int i = 0; i < m; i++)
    {
        int l = 0, r = 0;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    int ans = 0;
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            if (st != -2e9)
            {
                res.push_back({st, ed});
                ans += ed - st + 1;
                // printf("%d %d %d\n", st, ed, ans);
            }

            st = item.first;
            ed = item.second;
        }
        else
        {
            ed = max(ed, item.second);
        }
    }
    if (st != -2e9)
    {
        res.push_back({st, ed});
        ans += ed - st + 1;
        // printf("%d %d %d\n", st, ed, ans);
    }

    ans = l + 1 - ans;

    printf("%d\n", ans);
    return 0;
}