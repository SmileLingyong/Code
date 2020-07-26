/**
 * Creation         :       2019.06.23 11:25
 * Last Reversion   :       2019.06.23 11:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
subsetsII(子集II) 
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。
示例:
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsWithDupDFS(vector<int> &nums, int index, int target_size, vector<int> &out, vector<vector<int>> &res) {
    if (out.size() == target_size) {
        res.push_back(out);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) continue;  // 确保没有重复的集合
        out.push_back(nums[i]);
        subsetsWithDupDFS(nums, i + 1, target_size, out, res);
        out.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> out;
    sort(nums.begin(), nums.end());
    res.push_back({});
    for (int i = 1; i <= nums.size(); i++) {
        subsetsWithDupDFS(nums, 0, i, out, res);
    }
    return res;
}

int main() {
    vector<vector<int>> res;
    vector<int> nums;
    int x;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }
    res = subsetsWithDup(nums);
    for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << "[";
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}