/**
 * Creation         :       2019.07.18 23:59
 * Last Reversion   :       2019.07.19 00:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 0 ~ n-1 中缺失的数字
 * 题目描述
 *    一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围
 * 0 ～ n-1 之内。在范围 0 ～ n-1 内的 n 个数字中有且只有一个数字不在该数组中，
 * 请找出这个数字。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：直接遍历，首先判断第一个和最后一个，如果不是对应的，则直接返回
 * 对应的，则继续递增遍历，找到断点就是那个数字。
 * 时间复杂度： O(n^2)
 *  0  1  2  3
 * {0, 1, 2}
 */ 
int MissingNumber(vector<int> &nums) {
    if (nums.size() <= 1)
        return -1;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i+1] - nums[i] > 1)
            return nums[i] + 1;
    }
}

/**
 * 方法二：二分查找
 * 因为 0 ～ n-1 数字再数组中是排序的，因此数组开始的一些数字与它们的下标相同。
 * 如果不在数组中的那个数字记为m，那么所有比m小的数字的下标都与它们的值相同。
 * 比m大的值 x 的下标为 x-1.
 * (即将问题转换成在排序数组中查找出第一个值和下标不相等的元素)
 * 基于二分查找：
 * （1）nums[mid] == mid, 中间元素的值和下标相等，则右半部分继续查找
 * （2）nums[mid] != mid && nums[mid-1] == (mid-1)，中间元素的值和下标不等，
 * 并且其前一个元素的下标和值相等，则说明这个就是缺失的元素
 * （3）nums[mid] != mid && nums[mid-1] != (mid-1)，左半部分继续查找
 */
int MissingNumberII(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == mid) {
            l = mid + 1;
        } else {
            if (nums[mid - 1] == (mid - 1)) {
                return mid - 1;
            } else {
                r = mid - 1;
            }
        }
    } 
    return l;   
}


int main() {
    vector<int> nums = {0, 1, 2, 3};
    cout << MissingNumber(nums) << endl;
    cout << MissingNumberII(nums) << endl;
    return 0;
}