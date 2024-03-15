#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int n;
int a[N]; // 一分钟各个鱼塘能钓到鱼的个数
int b[N]; // 一分钟各个鱼塘钓鱼一次减少的数量
int l[N]; // 当前鱼塘到下一个鱼塘的分钟数

int spend[N]; // 在每个鱼塘所花费的时间

int T; // 时间限制

int get(int k)
{
    return max(0, a[k] - (b[k] * spend[k])); // 所得到的鱼数不可以是负数
}

// 这里的n代表线路的最后一个编号，T代表的是可以花费的钓鱼时间，路程时间在传递值的时候已经减去了
int work(int n, int T)
{
    // 进入贪心部分，枚举在每一个鱼塘钓鱼一分钟，求前T个最大的钓鱼数量
    int res = 0;                    // 钓鱼的数量
    memset(spend, 0, sizeof spend); // 初始化每个鱼塘花费的分钟数，每次调用函数都是一次新的路线
    for (int i = 1; i <= T; i++)
    {              // 每分钟都要去找最大的钓鱼数钓鱼
        int t = 1; // 这里的t永远在j的前面一个位置，可以找到最大的钓鱼数量
        for (int j = 2; j <= n; j++)
        {
            if (get(t) < get(j))
            {
                t = j;
            }
        }
        res += get(t);
        spend[t]++; // 每次选择最大的钓鱼数量，则在鱼塘花费+一分钟
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    // 这里因为第一个鱼塘到第二个鱼塘的时间是赋值给第二个鱼塘的，所以要从第二个鱼塘开始读入
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &l[i]);
        // 这里直接把路程读入成前缀和数组，方便后续可以直接求：枚举每条路线所用的时间
        l[i] += l[i - 1];
    }
    scanf("%d", &T);
    int res = 0;
    // 枚举每条路线所得到的钓鱼数量，取最大值
    for (int i = 1; i <= n; i++)
    {
        res = max(res, work(i, T - l[i]));
        // 这里的i就代表n条路线，因为选择的路径是不能反复横跳的，所以路径只有n条
        // 举例说明：i=1的时候，说明这条路径一直在1待着,i=2时，路径就是1-2
        // i为n时路径就是，1-2-3-4----n;
    }
    printf("%d\n", res);
    return 0;
}