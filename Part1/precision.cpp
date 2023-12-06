/*
大整数的计算：
1. 存储：高位在数组高索引，便于进位
2. 计算
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return false;
    if (A.size() > B.size())
        return true;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] > B[i])
            return true;
    }
    return false;
}

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t > 0)
            t = 0;
        else
            t = 1;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> mul(vector<int> &A, int b)
{
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

vector<int> div(vector<int> &A, int b, int &r)
{
    r = 0;
    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--)
    {
        A[i] += 10 * r;
        C.push_back(A[i] / b);
        r = A[i] % b;
    }

    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    int d, r = 0;

    // cin >> a >> b;
    cin >> a >> d;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    // for (int i = b.size() - 1; i >= 0; i--)
    //     B.push_back(b[i] - '0');

    // auto C = add(A, B);
    // vector<int> C;

    // if (cmp(A, B))
    // {
    //     C = sub(A, B);
    // }
    // else
    // {
    //     C = sub(B, A);
    //     printf("-");
    // }

    // auto C = mul(A, d);

    auto C = div(A, d, r);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    printf("\n%d", r);
    return 0;
}