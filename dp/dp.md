1. 动态规划 = 递归 + 记忆化
2. 每一项称为一个状态，想求解的任一目标值也是一个状态，`动态`就是有很多状态的，需要在状态间转移，规划出最优解的路线，需要状态转移方程
3. 状态定义：建数组
4. 状态转移方程：数组存值

```C++
/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？注意：给定 n 是一个正整数*/

int dp[N]; //dp[i]表示能到达第n阶的方法总数
dp[i] = dp[i-1]+dp[i-2]
int stairs(int n){
    if(n==1) return 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

```

```C++
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和

dp[i]：表示以 nums[i] 结尾的连续子数组的最大和
如果要得到dp[i]，那么nums[i]一定会被选取。并且 dp[i] 所表示的连续子序列与 dp[i-1] 所表示的连续子序列很可能就差一个 nums[i] 。即dp[i] = dp[i-1]+nums[i] , if (dp[i-1] >= 0)

这里我们遇到一个问题，很有可能dp[i-1]本身是一个负数。那这种情况的话，如果dp[i]通过dp[i-1]+nums[i]来推导，那么结果其实反而变小了，因为我们dp[i]要求的是最大和。所以在这种情况下，如果dp[i-1]<0，那么dp[i]其实就是nums[i]的值。即dp[i] = nums[i] , if (dp[i-1] < 0)

dp[0] = nums[0]

综上dp[i]=max(nums[i], dp[i−1]+nums[i])
最终的答案是寻找max(dp[0], dp[1], ..., d[i-1], dp[i])
*/
int maxSubArray(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
}
```

```C++
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 设计一个算法来计算你所能获取的最大利润。你最多可以完成 2笔交易（买一次再卖一次）
交易数 天数 => 二维数组

dp[k][i]  第 i 天最多 k 笔交易的情况下的最大利润
dp[k][i] = max(dp[k][i-1],dp[k-1][i-1]+prices[i])
要么是我昨天就除天数外一模一样的状态DP[k][i-1]，今天啥也不干；要么是我昨天最大利润的状态是DP[k-1][i-1]，但是今天我卖了一支股票，所以我获得 prices[i]的利润

DP[k][i] = Math.max(DP[k][i - 1], prices[i] + tmpMax); tmpMax = Math.max(tmpMax, DP[k-1][i-1] - prices[i]);
解释：今天最大利润的状态是DP[k][i]，有两种可能： 要么是我昨天就除天数外一模一样的状态DP[k][i-1]，今天啥也不干； 要么是我昨天或者之前哪一天最大利润的状态是DP[k-1][i-1]，然后今天我卖了一支股票，所以我获得 prices[i]的利润
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 

int main(){
    return 0;
}
```

```C++
/*
给定一个无序的整数数组，找到其中最长上升子序列的长度
dp[i]表示以第i个元素为结尾的最长上升子序列的长度

for (int j = 0; j < i; j++)
    if nums[j] < nums[i]
        dp[i] = max(dp[j] + 1)
*/
// 该函数求 nums 序列的最长子序列
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // 特判空序列
    if (n == 0) return 0;

    // 状态数组，初始化成1，因为各个元素可以单独构成一个上升序列
    vector<int> dp(n, 1);

    // 从nums[1] 开始遍历整个数组
    for (int i = 1; i < n; i++) {
        // 从前往后比那里之前的元素
        for (int j = 0; j < i; j++) {
            // j 位置的元素值小于 i 位置的元素值，则 nums[i] 可以拼接在 nums[j] 后面
            if (nums[j] < nums[i]) { 
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 状态数组中最大的值就是最长上升子序列的长度
    return *max_element(dp.begin(), dp.end());
}

```