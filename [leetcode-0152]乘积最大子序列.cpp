/**
 * Creation         :       2019.07.11 17:57
 * Last Reversion   :       2019.07.11 18:30
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
maxProduct (乘积最大子序列)
给定一个整数数组
nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：暴力穷举
 * 时间复杂度： O(n^2) 超时！
 */ 
int maxProduct(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    int max_mul = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        int cur_mul = nums[i];
        max_mul = max(max_mul, cur_mul);
        for (int j = i + 1; j < nums.size(); j++) {
            cur_mul *= nums[j];
            max_mul = max(max_mul, cur_mul);
        }
    }
    return max_mul;
}


/**
 * 方法二：动态规划 在leetcode-53上改进
 * 遍历数组时计算当前最大值，不断更新
 * 令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
 * 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前
 * 最小值imin，imin = min(imin * nums[i], nums[i])
 * 当负数出现时则imax与imin进行交换再进行下一步计算
 * 时间复杂度：O(n)
 */
int maxProductII(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int max_num = nums[0];
    int imax = 1, imin = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            int temp = imax;
            imax = imin;
            imin = temp;
        }
        imax = max(imax * nums[i], nums[i]);
        imin = min(imin * nums[i], nums[i]);
        max_num = max(max_num, imax);
    }
    return max_num;
}

int main() {
    vector<int> nums = {3, -2, -4};
    // vector<int> nums = {0, 2};
    cout << maxProduct(nums) << endl;
    cout << maxProductII(nums) << endl;
    return 0;
}