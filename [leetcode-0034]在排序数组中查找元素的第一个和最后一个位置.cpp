/**
 * Creation         :       2019.07.13 09:36
 * Last Reversion   :       2019.07.13 11:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
searchRange（在排序数组中查找元素的第一个和最后一个位置）
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 原始二分查找：查找数组中是否存在x
 */ 
int BinarySearch(vector<int> data, int l, int r, int x) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (data[mid] == x)
            return mid;
        else if (data[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

/**
 * 二分查找：查找第一个大于等于 x 的数，存在返回索引，不存在返回-1
 */ 
int BinarySearchII(vector<int> data, int l, int r, int x) {
    int mid, start = l, end = r;
    while (l != r) {                    // 注意这里是 != 
        mid = (l + r) / 2;
        if (data[mid] < x)
            l = mid + 1;
        else 
            r = mid;
    }
    return (l < 0 || l > end || data[l] != x) ? -1 : l;   // 判断第一个大于等于x的数是否是x，即x是否存在，不存在返回-1
}


/**
 * 二分查找：查找最后一个小于等于 x 的数，存在返回索引，不存在返回-1
 */ 
int BinarySearchIII(vector<int> data, int l , int r, int x) {
    int mid, start = l, end = r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (data[mid] <= x) 
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return (r < 0 || r > end || data[r] != x ? -1 : r); 
}

/**
 * 方法一：使用两次二分查找
 */
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) return {-1, -1};
    if (nums.size() == 1) 
        return nums[0] == target ? vector<int>(2, 0) : vector<int>(2, -1);
    vector<int> res;
    res.push_back(BinarySearchII(nums, 0, nums.size() - 1, target));
    res.push_back(BinarySearchIII(nums, 0, nums.size() - 1, target));
    return res;
}

/* -------------------------------------------------------------------------------------------- */
/**
 * 二分查找：查找第一个大于等于 x 的数，存在则，继续找其前面是否是一样的，从而确定范围。不存在则返回 {-1, -1}
 */ 
vector<int> BinarySearchIV(vector<int> data, int l, int r, int x) {
    int mid, start = l, end = r, left, right;
    while (l != r) {                // 注意这里是 != 
        mid = (l + r) / 2;
        if (data[mid] < x)
            l = mid + 1;
        else 
            r = mid;
    }
    if (data[l] == x) {
        left = l;
        right = l;
        while (right + 1 <= end && data[right + 1] == x) {
            right++;
        }
        return {left, right};
    } else {
        return {-1, -1};
    }
}

/**
 * 方法二：使用一次二分查找
 */ 
vector<int> searchRangeII(vector<int>& nums, int target) {
    if (nums.size() == 0) return {-1, -1};
    if (nums.size() == 1) 
        return nums[0] == target ? vector<int>(2, 0) : vector<int>(2, -1);
    return BinarySearchIV(nums, 0, nums.size() - 1, target);
}

int main() {
    vector<int> nums = {2, 2, 3};
    int target = 2;
    vector<int> res = searchRangeII(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}