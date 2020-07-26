/**
 * Creation         :       2019.07.11 17:57
 * Last Reversion   :       2019.07.11 18:30
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
maxSubArray (最大子序和)
给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：动态规划
 * （1）定义状态： dp[i] 表示到下标 i 为止，最大的连续子数组和
 * （2）状态转移方程： dp[i] = max(dp[i-1] + nums[i], nums[i]) 
 * 表示到i这个位置，选 nums[i]，还是不选nums[i]，我们选结果大的更新dp[i]
 */ 
int maxSubArray(vector<int>& nums) {
    if (nums.size() <= 0) return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int sum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        sum = max(sum, dp[i]);
    }
    return sum;
}


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}