/**
 * Creation         :       2019.07.13 09:36
 * Last Reversion   :       2019.07.13 11:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
search（搜索旋转排序数组）
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &nums, int l, int r, int key);
int FindRotateIndex(vector<int> &nums, int l, int r);

/**
 * 方法一：顺序遍历即可
 * 时间复杂度：O(n) 时间复杂度没达到要求！
 */ 
int search(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}


/**
    方法二：直接二分法
    直接使用二分法，判断那个二分点,有几种可能性
    1. 直接等于target
    2. 在左半边的递增区域
        a. target 在 left 和 mid 之间
        b. 不在之间
    3. 在右半边的递增区域
        a. target 在 mid 和 right 之间
        b. 不在之间
 */ 
int searchII(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) 
            return mid;
        else if (nums[left] <= nums[mid]) 
            if (target >= nums[left] && target < nums[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        else
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else 
                right = mid - 1;
    }
    return nums[left] == target ? left : -1;
}


/**
 * 方法三：使用两次二分查找 （复杂，一时半会写不出来的）
 * 先使用一次二分查找，找到旋转数组的最小数字
 * 然后就可以知道target在旋转数组的左右那个部分，然后再使用一次二分查找即可
 * 时间复杂度：O(logn)
 */ 
int searchIII(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0) return -1;
    if (len == 1) return nums[0] == target ? 0 : -1;
    // 找到旋转最小数字的索引
    int rotate_index = FindRotateIndex(nums, 0, len-1);
    // 根据索引然后再进行一次二分查找
    // 最小数字就是目标值
    if (nums[rotate_index] == target) 
        return rotate_index;
    // 最小数字是第一个，即原数组是升序排序好的
    if (rotate_index == 0)
        return BinarySearch(nums, 0, len - 1, target);
    // 若 target 比 nums[0] 小，则说明在旋转数组右半部分，再对右半部分二分查找即可
    if (target < nums[0])   
        return BinarySearch(nums, rotate_index, len - 1, target);
    else 
        return BinarySearch(nums, 0, rotate_index - 1, target);
}

/**
 * 二分查找，找到旋转数组最小数字索引
 */ 
int FindRotateIndex(vector<int> &nums, int l, int r) {
    if (nums[l] < nums[r]) return 0;    // 已经是升序的，未旋转，直接返回第一个元素索引0即可
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])  // 当前的比后面一个大，则说明后面那个为最小的
            return mid + 1;
        else {
            if (nums[mid] < nums[l])    // 旋转数字在左边
                r = mid;
            else                        // 旋转数字在右边
                l = mid + 1;
        }
    }
}

/**
 * 二分查找，查找数组中是否存在 key 元素
 */ 
int BinarySearch(vector<int> &nums, int l, int r, int key) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] < key) 
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


int main() {
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1, 3};
    int target = 3;
    cout << search(nums, target) << endl;
    cout << searchII(nums, target) << endl;
    return 0;
}