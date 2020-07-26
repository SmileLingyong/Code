/**
 * Creation         :       2019.05.28 20:31
 * Last Reversion   :       2019.05.28 20:31
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * (n皇后问题II)
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
示例:
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum = 0;

int CanPut(vector<int> &queen, int row) {
    for (int j = 0; j < row; j++) {
        if (queen[row] == queen[j] || abs(queen[j] - queen[row]) == (row-j))
            return 0;
    }
    return 1;
}

int Putqueen(int row, vector<int> &queen, int n) {
    if (row >= n) {
        sum ++;
    } else {
        for (int i = 0; i < n; i++) {
            queen[row] = i;
            if (CanPut(queen, row)) {
                Putqueen(row + 1, queen, n);
            }
        }
    }
    return sum;
}

int totalNQueens(int n) {
    vector<int> queen(n);
    return Putqueen(0, queen, n);
}

int main() {
    int n;
    cin >> n;
    sum = totalNQueens(n);
    cout << "sum = " << sum;
    return 0;
}
