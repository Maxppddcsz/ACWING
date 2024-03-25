#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1010;

int n;
double h, r;
int T;
struct Point
{
    double x, y, z;
} points[N];

int p[N];

int find(int x)
{
    if (p[x] != x)
    {
        return find(p[x]);
    }
    return p[x];
}

double get(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++)
        {
            cin >> points[i].x >> points[i].y >> points[i].z;
            p[i] = i;
        }

        p[0] = 0, p[n + 1] = n + 1;

        for (int i = 1; i <= n; i++)
        {
            struct Point down = {points[i].x, points[i].y, 0};
            struct Point up = {points[i].x, points[i].y, h};
            if (get(down, points[i]) < r || fabs(get(down, points[i]) - r) < 1e-15)
                p[find(i)] = find(0); // 注意double类型的精度到1e-15，float到1e-6，这里要准确判断精度，否则会有一个测试点卡住
            if (get(up, points[i]) < r || fabs(get(up, points[i]) - r) < 1e-15)
                p[find(i)] = find(n + 1);
        }

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                if ((get(points[i], points[j]) < 2 * r || fabs(get(points[i], points[j]) - 2 * r) < 1e-15) && find(i) != find(j))
                    p[find(i)] = find(j);
            }

        // for(int i = 0; i <= n + 1; i++ )
        //     cout << p[i] << endl;

        if (find(0) == find(n + 1))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}