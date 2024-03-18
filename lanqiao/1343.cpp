#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 5010;
int n;
vector<PII> segs, res;

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;

    for (int i = 0; i < n; i++)
    {
        auto item = segs[i];
        if (ed < item.first)
        {
            if (st != -2e9)
            {
                res.push_back({st, ed});
                // printf("push %d %d\n", st, ed);
            }
            st = item.first;
            ed = item.second;
        }
        else
        {
            ed = max(ed, item.second);
        }
    }

    // printf("\n\n");
    if (st != -2e9)
        res.push_back({st, ed});

    segs = res;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < segs.size(); i++)
    {
        auto item = segs[i];
        // printf("%d %d\n", item.first, item.second);
    }

    for (int i = 0; i < segs.size(); i++)
    {

        ans1 = max(ans1, segs[i].second - segs[i].first);
        if (i > 0)
        {
            ans2 = max(ans2, segs[i].first - segs[i - 1].second);
        }
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}