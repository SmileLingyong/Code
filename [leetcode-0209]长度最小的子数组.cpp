/**
 * Creation         :       2019.08.19 20:36
 * Last Reversion   :       2019.08.19 19:42
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

进阶:
如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
using namespace std;
/**
 * 方法一：使用双指针，直接遍历
 * 时间复杂度：O(n)
 */ 
int minSubArrayLen(int s, vector<int>& nums) {
    int length = nums.size();
    if (length == 0 || s <= 0)
        return 0;
    int left = 0, right = 0, counter = 0, min_len = 0x7fffffff;
    int cur_sum = 0;
    while (right < length) {
        if (cur_sum < s) {
            cur_sum += nums[right];
            right ++;
        }
        while (cur_sum >= s) {
            min_len = min(min_len, right - left);
            cur_sum -= nums[left];
            left ++;
        }
    }
    return min_len == 0x7fffffff ? 0 : min_len;
}


int main() {
    vector<int> nums;
    int s, x;
    while (true) {
        cin >> x;
        nums.push_back(x);
        if (getchar() == '\n')
            break;
    }
    cin >> s;
    cout << minSubArrayLen(s, nums) << endl;
    return 0;
}