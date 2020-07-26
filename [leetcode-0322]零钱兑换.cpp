/**
 * Creation         :       2019.08.25 11:36
 * Last Reversion   :       2019.08.25 11:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

示例 2:
输入: coins = [2], amount = 3
输出: -1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
        for (auto coin : coins) {
            if (i >= coin) 
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}


int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;
    return 0;
}