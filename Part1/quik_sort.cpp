#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N];
void quik_sort(int q[], int l, int r)
{
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    if (l >= r) // 边界
        return;
    while (i < j) // 双指针，交换
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    quik_sort(q, l, j); // 递归
    quik_sort(q, j + 1, r);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    quik_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }
    return 0;
}