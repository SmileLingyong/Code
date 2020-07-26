/**
 * Creation         :       2019.06.01 17:20
 * Last Reversion   :       2019.06.01 17:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * removeDuplicates(删除排序数组中的重复项 II) 结合leetcode-26 一起看
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1)
额外空间的条件下完成。 示例 1: 给定 nums = [1,1,1,2,2,3], 函数应返回新长度
length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,1,2,3,3],
函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3
。 你不需要考虑数组中超出新长度后面的元素。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：
这里允许最多重复的次数是两次，那么我们就需要用一个变量count来记录还允许有几次重复，
count初始化为1，如果出现过一次重复，则count递减1，那么下次再出现重复，快指针直接
前进一步，如果这时候不是重复的，则count恢复1，由于整个数组是有序的，所以一旦出现不
重复的数，则一定比这个数大，此数之后不会再有重复项.
 */
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;
    int pre = 0, cur = 1, n = nums.size(), count = 1;
    while (cur < n) {
        if (nums[pre] == nums[cur] && count == 0) {
            cur++;
        } else {
            if (nums[pre] == nums[cur]) {
                count--;
            } else {
                count = 1;
            }
            nums[++pre] = nums[cur++];
        }
    }
    return pre + 1;
}

int main() {
    vector<int> nums;
    int x;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }

    int len = removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}