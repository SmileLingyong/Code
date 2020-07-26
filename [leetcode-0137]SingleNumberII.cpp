/**
 * Creation         :       2019.06.27 11:08
 * Last Reversion   :       2019.06.27 11:19
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
singleNumberII(只出现一次的数字)
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,3,2]
输出: 3

示例 2:
输入: [0,1,0,1,0,1,99]
输出: 99

思路：
   继续利用计算机按位储存数字的特性来做，这道题就是除了一个单独的数字之外，数组中其他的数字都出现了三次，
那么还是要利用位操作 Bit Operation来解此题。我们可以建立一个32位的数字，来统计每一位上1出现的个数，我
们知道如果某一位上为1的话，那么如果该整数出现了三次，对3去余为0，我们把每个数的对应位都加起来对3取余，最
终剩下来的那个数就是单独的数字。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    return res;
}

int main() {
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums) << endl;
    return 0;
}