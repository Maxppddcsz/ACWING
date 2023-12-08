/*
整数的离散化(有序)
0. a是有序的 -> 排序
1. a数组中可能有重复元素 -> 去重 unique
2. 如何算出x离散后在a中的下标i -> 二分查找
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int const N = 300010;
/*将对坐标的操作和坐标里的数据两者均离散化*/
int a[N], s[N];

vector<int> all;

typedef pair<int, int> PII;
vector<PII> add;
vector<PII> query;

int find(int x)
{
    int l = 0, r = all.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (all[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int main()
{
    int n, m;
    int x, c;
    int l, r;
    cin >> n >> m;
    while (n--)
    {
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }

    while (m--)
    {
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    for (auto item : add)
    {
        x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= all.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    for (auto item : query)
    {
        l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}