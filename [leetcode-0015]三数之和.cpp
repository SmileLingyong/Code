/**
 * Creation         :       2019.07.11 23:53
 * Last Reversion   :       2019.07.11 23:53
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
threeSum (三数之和)
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a
+ b + c = 0 ？ 找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> &nums, int index, int target, vector<int> &out,
         vector<vector<int>> &res) {
    if (out.size() == 3) {
        if (target == 0) {
            res.push_back(out);
            return;
        } else {
            return;
        }
    }
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1])
            continue;  // 保证不重复使用nums[i]
        out.push_back(nums[i]);
        DFS(nums, i + 1, target - nums[i], out, res);
        out.pop_back();
    }
}

/**
 * 方法一：DFS思想
 * 时间复杂度：O(n^2) 超时！
 */ 
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> out;
    sort(nums.begin(), nums.end());  // 先排序
    DFS(nums, 0, 0, out, res);
    return res;
}


/**
方法二：使用三指针来处理 (要多看多巩固几遍)
首先对数组进行排序，排序后固定一个数nums[i]，再使用左右指针指向nums[i]后面的两端，
数字分别为nums[L]和nums[R]，计算三个数的和sum判断是否满足为 0，满足则添加进结果集

如果nums[i]大于 0，则三数之和必然无法等于 0，结束循环
如果nums[i] == nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
当sum == 0 时，nums[L] == nums[L+1]则会导致结果重复，应该跳过，L++
当sum == 0 时，nums[R] == nums[R−1]则会导致结果重复，应该跳过，R--
时间复杂度：O(n^2)，n为数组长度
Reference：https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/
 */ 
vector<vector<int>> threeSumII(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (nums.empty() || len < 3) return {};
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0)  break;    // 如果当前数字大于0，则三数之和一定大于0，循环结束
        if (i > 0 && nums[i] == nums[i-1]) continue;    // 去重
        int L = i + 1;
        int R = len - 1;
        while (L < R) {
            int sum = nums[i] + nums[L] + nums[R];
            if (sum == 0) {
                vector<int> out = {nums[i], nums[L], nums[R]};
                res.push_back(out);
                while (L < R && nums[L] == nums[L + 1]) // 去重
                    L++;
                while (L < R && nums[R] == nums[R - 1]) // 去重
                    R--;
                L++;
                R--;
            } else if (sum < 0) {
                L++;
            } else if (sum > 0) {
                R--;
            }
        }
    }
    return res;
}

int main() {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0, 0};
    // vector<vector<int>> res = threeSum(nums);
    vector<vector<int>> res = threeSumII(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}