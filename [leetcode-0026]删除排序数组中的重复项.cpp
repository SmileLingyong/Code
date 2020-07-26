/**
 * Creation         :       2019.06.01 16:25
 * Last Reversion   :       2019.06.01 16:25
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * removeDuplicates(删除排序数组中的重复项)
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1)
额外空间的条件下完成。 示例 1: 给定数组 nums = [1,1,2], 函数应该返回新的长度 2,
并且原数组 nums 的前两个元素被修改为 1, 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * 方法一：简洁版本(使用快慢指针)
 使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，如果两个指针指
 的数字相同，则快指针向前走一步，如果不同，则两个指针都向前走一步，这样当快指针
 走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数，
 */ 
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int pre = 0, cur = 0, n = nums.size();
    while (cur < n) {
        if (nums[pre] == nums[cur]) 
            cur++;
        else 
            nums[++pre] = nums[cur++];
    }
    return pre+1;
}

/**
 * 方法二：自己写的，从后向前遍历
 */ 
int removeDuplicatesII(vector<int>& nums) {
    if (nums.size() == 1) return nums.size();

    int l = nums.size() - 2;
    int r = nums.size() - 1;
    while (l >= 0) {
        if (nums[l] == nums[r]) {
            while (l >= 0 && nums[l] == nums[r]) {
                l--;
            }
            nums.erase(nums.begin() + l + 2, nums.begin() + r + 1);
            r = l + 1;
        }
        l--;
        r--;
    }
    return nums.size();
}

int main() {
    vector<int> nums;
    int x;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }
    
    int len = removeDuplicatesII(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}