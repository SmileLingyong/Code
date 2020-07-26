/**
 * Creation         :       2019.07.27 19:30
 * Last Reversion   :       2019.07.27 19:30
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
canJump （跳跃游戏）
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2,3,1,1,4]

输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。

示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */


#include <iostream>
#include <vector>
using namespace std;

/**
    方法一：贪心思想
    用 reach 来保存可以跳到的最远位置，通过 nums[i] + i 来更新 reach
    (1) 当 i > reach 时，即不能能从前面跳到这个位置，返回False（自己Debug一下就明白）
    (2) 当 reach >= n-1 即最远可以调到 最后一个位置，返回 True
 */ 
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reach = 0;
    for (int i = 0; i < n; i++) {
        if (i > reach) 
            return false;
        if (reach >= n - 1)
            return true;
        reach = max(reach, i + nums[i]);
    }
    return true;
}


/**
    方法二：动态规划
    dp[i]：表示到第 i 个位置时，还可以跳几步（即剩余步数）
    达到当前位置的剩余步数 和 上一个位置的剩余步数dp[i-1] 和 上一个位置的跳力有关nums[i-1]
    当前位置的剩余步数 dp[i]等于 上面两者最大的 减去 1, 因为要花一个跳力到达下一个位置。
    状态转移方程： dp[i] = max(dp[i - 1], nums[i - 1]) - 1
    如果 dp为负数，说明无法抵达当前位置，直接返回false
 */ 
bool canJumpII(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
        if (dp[i] < 0)
            return false;
    }
    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;
    return 0;
}