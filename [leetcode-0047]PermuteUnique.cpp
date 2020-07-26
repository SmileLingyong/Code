/**
 * Creation         :       2019.06.01 14:42
 * Last Reversion   :       2019.06.01 14:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * permuteUnique(全排列)
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void FullyArrange(vector<int> &nums, int index, set<vector<int>> &res_set) {
    if (index >= nums.size()) {
        res_set.insert(nums);
    }
    for (int j = index; j < nums.size(); j++) {
        Swap(nums[j], nums[index]);
        FullyArrange(nums, index + 1, res_set);
        Swap(nums[j], nums[index]);
    }
}

/**
 * 方法一：全排列的思想生成排列，存储与set中，这样就可以除去重复的元素
 */ 
vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> res_set;
    vector<vector<int>> res;
    FullyArrange(nums, 0, res_set);
    for (set<vector<int>>::iterator iter = res_set.begin(); iter != res_set.end(); iter++) {
        res.push_back(*iter);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}