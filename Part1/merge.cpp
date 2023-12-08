/*
1. 按区间左端点排序
2. 扫描区间：a.包含关系 (不管)b.交集关系(合并) c.无交集(加一) -> 更新
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 1e5 + 10;

typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    sort(segs.begin(), segs.end());
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = item.first;
            ed = item.second;
        }
        else
        {
            ed = max(ed, item.second);
        }
    }
    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}