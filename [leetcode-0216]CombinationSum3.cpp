/**
 * Creation         :       2019.06.23 10:52
 * Last Reversion   :       2019.06.23 11:05
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * combinationSumIII(组合总和III) 
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

void combinationSum3DFS(int k, int target, int index, vector<int> &out, vector<vector<int>> &res) {
    if (target < 0) return;
    if (target == 0 && out.size() == k) {
        res.push_back(out);
        return;
    }
    for (int i = index; i <= 9; i++) {
        out.push_back(i);
        combinationSum3DFS(k, target - i, i + 1, out, res); // 注意，这里要传入 i + 1,保证不适用重复的元素
        out.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> out;
    combinationSum3DFS(k, n, 1, out, res);
    return res;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> res = combinationSum3(k, n);
    for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << "[";
        for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}