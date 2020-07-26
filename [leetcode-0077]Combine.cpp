/**
 * Creation         :       2019.06.01 11:10
 * Last Reversion   :       2019.06.01 11:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
combine(组合)
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 像这种要求出所有结果的集合，一般都是用DFS调用递归来解(结合全排列等)
 */ 
void DFS(int n, int k, int index, vector<int> &out, vector<vector<int>> &res) {
    if (out.size() == k) {
        res.push_back(out);
        return;
    }
    for (int i = index; i <= n; i++) {
        out.push_back(i);
        DFS(n, k, i + 1, out, res);
        out.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> out;
    DFS(n, k, 1, out, res);
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums = combine(n, k);
    for (vector<vector<int>>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
        vector<int>::iterator it = (*iter).begin();
        for (; it != (*iter).end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}