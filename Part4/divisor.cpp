/*
如果 a / b = c···0，则一定有 a % c = b····0。所以一个数 x 的约数肯定是成对存在的，对称轴是 根号x。
因此，只需要用 x 除以 1 到 根号x 之间的数，如果余数是0，则把除数以及x / 除数加到答案中
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> res;
        //因为约数成对出现，所以只需要循环到根号x
        // 不要是用 i *i <= n，因为可能溢出
        for(int i = 1; i <= n /i; i++)
        {
            if(n % i == 0)
            {
                res.push_back(i);
                //如果i * i = x,添加i即可，不用添加 x / i
                if(n / i != i)
                    res.push_back(n / i);
            }
        }
        sort(res.begin(), res.end());
        for(auto x : res) cout << x << " ";
        cout << endl;

    }
}