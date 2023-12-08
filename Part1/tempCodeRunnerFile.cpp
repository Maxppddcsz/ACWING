
const int n = 1e5 + 10;

typedef pair<int, int> PII;

vector<PII> segs;

void merge()
{
    vector<PII> res;
    int st = -1e9, ed = -1e9;
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            res.push_back({item.first, item.second});
            st = item.first;
            ed = item.second;
        }
        else
        {
            ed = max(ed, item.second);
        }
    }
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
    merge();
    cout << segs.size() << endl;
    return 0;
}