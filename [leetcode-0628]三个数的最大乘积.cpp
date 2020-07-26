/**
 * Creation         :       2019.07.11 21:06
 * Last Reversion   :       2019.07.11 21:26
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
maximumProduct (三个数的最大乘积)
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
示例 1:
输入: [1,2,3]
输出: 6

示例 2:
输入: [1,2,3,4]
输出: 24
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法一：数学 排序
 * 不要上来就以为是动态规划，这个只是要求3个数最大乘积，所以可以先排序，由于存在负数，
 * 所以有以下两种情况：
 * （1）最大的三个正数：            nums[n-1] * nums[n-2] * nums[n-3]
 * （2）最大的正数 * 最小的两个负数： nums[n-1] * nums[0] * nums[1]
 * 然后取他们的最大值即可。
 */ 
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return max(nums[n-1] * nums[n-2] * nums[n-3], nums[n-1] * nums[0] * nums[1]);
}

int main() {
    vector<int> nums = {-4, -3, -2, 60};
    cout << maximumProduct(nums) << endl;
    return 0;
}