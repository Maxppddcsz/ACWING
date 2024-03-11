#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int p[N];
int t[N];
int b[N];
int k[N];
int n;

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        b[i] = p[i] - p[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        k[i] = p[i] - t[i];
    }

    return 0;
}