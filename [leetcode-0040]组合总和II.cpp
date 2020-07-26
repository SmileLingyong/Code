/**
 * Creation         :       2019.06.21 17:52
 * Last Reversion   :       2019.06.21 19:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * combinationSumII(组合总和II) 
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使
数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
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
#include <algorithm>
using namespace std;

void combinationSum2DFS(vector<int> &candidates, int target, int index, vector<int> &out, vector<vector<int>> &res) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(out);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i-1]) continue;   // 保证res中没有重复的
        out.push_back(candidates[i]);
        combinationSum2DFS(candidates, target - candidates[i], i + 1, out, res);    // i + 1，就不会重复使用当前数字了
        out.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> out;
    sort(candidates.begin(), candidates.end());
    combinationSum2DFS(candidates, target, 0, out, res);
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
    res = combinationSum2(candidates, target);

    for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << "[";
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}