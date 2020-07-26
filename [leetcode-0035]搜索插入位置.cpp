/**
 * Creation         :       2019.04.23 11:42
 * Last Reversion   :       2019.04.23 11:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * SearchInsert(搜索插入位置) 
 * 题目描述
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：使用二分查找
 */ 
int searchInsert(vector<int>& nums, int target) {
    if (target > nums[nums.size()-1])   // 对边界条件先进行判断
        return nums.size();
    if (target < nums[0])
        return 0;
    // 以下是原始的二分查找
    int l = 0, r = nums.size() - 1, mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main() {
    vector<int> nums;
    int target, x;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }
    cin >> target;
    cout << searchInsert(nums, target) << endl;
    return 0;
}