/**
 * Creation         :       2019.07.27 19:30
 * Last Reversion   :       2019.07.27 19:30
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
jump （跳跃游戏II）
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
输入: [2,3,1,1,4]
输出: 2

解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:
假设你总是可以到达数组的最后一个位置。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：贪心思想
 * 每次再可跳范围内选择可以使得跳的更远的额位置
 */ 
bool jump(vector<int>& nums) {
    int n = nums.size();
    int step = 0, reach = 0, end = 0;       // 分别记录步数、当前位置能到达的最远位置，能跳范围的边界
    for (int i = 0; i < n - 1; i++) {       // 因为 i == 0 的时候已经+1了，所以最后调到末尾位置的时候就不用+1了，所以这里用的是 < n - 1
        reach = max(reach, nums[i] + i);
        if (i == end) {                     // 遇到边界，就更新边界，并且步数加一
            end = reach;
            step++;
        }
    }
    return step;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}