/**
 * Creation         :       2019.07.12 13:38
 * Last Reversion   :       2019.07.12 13:54
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
fourSum（四数之和）
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个
元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件
且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：先排序，然后固定两个数，后面部分再使用两个指针，不断缩小指针范围
 * 注意其中去重的部分即可。
 */ 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int len = nums.size();
    if (len < 4) return {};
    sort(nums.begin(), nums.end());
    int L, R, sum;
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;          // 第一个去重
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j - i > 1 && nums[j] == nums[j - 1]) continue;  // 第二个去重
            L = j + 1;
            R = len - 1;
            while (L < R) {
                sum = nums[i] + nums[j] + nums[L] + nums[R];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1]) L++;    // 去重
                    while (L < R && nums[R] == nums[R - 1]) R--;    // 去重
                    L++;
                    R--;
                } else if (sum < target) {
                    L++;
                } else if (sum > target) {
                    R--;
                }
            }
        }
    }
    return res;
}

int main() {
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}