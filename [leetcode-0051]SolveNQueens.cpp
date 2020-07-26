/**
 * Creation         :       2019.05.08 16:24
 * Last Reversion   :       2019.05.08 16:24
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * (n皇后问题)
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
示例:
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > res;

/**
 * 方法一：回溯
 */ 
int CanPut(vector<int> &queen, int row) {
    for (int j = 0; j < row; j++) {
        if (queen[row] == queen[j] || abs(queen[j] - queen[row]) == (row-j))
            return 0;
    }
    return 1;
}

vector<vector<string> > Putqueen(int row, vector<int> &queen, int n) {
    if (row >= n) {
        vector<string> one_res;
        for (int i = 0; i < n; i++) {
            string row_data = "";
            for (int j = 0; j < n; j++) {
                if (queen[i] == j) {
                    row_data += "Q";
                } else {
                    row_data += ".";
                }
            }
            one_res.push_back(row_data);
        }
        res.push_back(one_res);
    } else {
        for (int i = 0; i < n; i++) {
            queen[row] = i;
            if (CanPut(queen, row)) {
                Putqueen(row + 1, queen, n);
            }
        }
    }
    return res;
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> queen(n);
    return Putqueen(0, queen, n);
}

int main() {
    int n;
    cin >> n;
    vector<vector<string> > res;
    res = solveNQueens(n);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
