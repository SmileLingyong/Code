/**
 * Creation         :       2019.06.27 10:56
 * Last Reversion   :       2019.06.27 11:00
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
singleNumber(只出现一次的数字) 
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4

思路：
   两个相同的数异或的结果为 0，对所有数进行异或操作，最后的结果就是单独出现的那个数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 4};
    cout << singleNumber(nums) << endl;
    return 0;
}