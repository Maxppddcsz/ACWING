#include<iostream>
#include<unordered_map>
/*
(p1^0+p1^1+…+p1^c1)∗…∗(pk^0+pk^1+…+pk^ck)
*/
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)primes[x]++;
    }

    LL res = 1;
    for (auto p : primes)
    {
        LL a = p.first, b = p.second;
        LL t = 1;
        while (b--) t = (t * a + 1) % mod;
        res = res * t % mod;
    }

    cout << res << endl;
    return 0;
}
