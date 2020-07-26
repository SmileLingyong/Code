/**
 * Creation         :       2019.06.21 16:04
 * Last Reversion   :       2019.06.21 17:45
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * combinationSum(组合总和) 
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为: 
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

思路：和组合，排列的那些题目都是一个套路
   需要另写一个递归函数，这里我们新加入三个变量，index记录当前的递归到的下标，
out为一个解，res保存所有已经得到的解，每次调用新的递归函数时，此时的target
要减去当前数组的的数
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void combinationSumDFS(vector<int> candidates, int target, int index, vector<int> &out, vector<vector<int>> &res) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(out);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        out.push_back(candidates[i]);
        combinationSumDFS(candidates, target - candidates[i], i, out, res); 
        // 注意，这里传入的是 i 而不是 index，保证以前重复使用过的不再回溯使用，即保证没有重复的组合
        out.pop_back();     // 如果加上下一个之后大于target了，则回溯到上一步
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> out;
    combinationSumDFS(candidates, target, 0, out, res);
    return res;
}

int main() {
    vector<vector<int>> res;
    vector<int> candidates;
    int target, x;
    while (cin >> x && x != -1) {
        candidates.push_back(x);
    }
    cin >> target;
    res = combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}