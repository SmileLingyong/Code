/**
 * Creation         :       2019.07.10 00:03
 * Last Reversion   :       2019.07.10 00:03
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
GetMaxGiftVal(礼物最大值) 
题目描述
在一个m*n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一格，知道到达棋盘的右下角。
给定一个棋盘及其上面的礼物，请计算你最多能拿多少价值的礼物？
    1   10  3   8
    12  2   9   6
    5   7   4   11
    3   7   16  5
在这个棋盘中，按照（1，12，5，7，7，16，5）= 53 的顺序可以拿到总价值最大的礼物。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */ 
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：动态规划
 * 我们有两种可能途径到达坐标为(i, j)的格子：通过 (i-1, j) 或者 (i, j-1)
 * 所以 dp(i, j) = max(dp(i-1, j), dp(i, j-1)) + gift[i, j]，
 * gift[i, j] 表示坐标为(i, j)的格子里礼物的价值
 */ 
int getMaxValue(const int *values, int rows, int cols) {
    if (values == NULL || rows <= 0 || cols <= 0)
        return 0;
    vector<vector<int>> max_vals(rows, vector<int>(cols));  // 初始化二维数组
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int left = 0;
            int up = 0;
            if (i > 0) 
                up = max_vals[i-1][j];
            if (j > 0) 
                left = max_vals[i][j-1];
            max_vals[i][j] = max(left, up) + values[i * cols + j];
        }
    }
    int max_val = max_vals[rows - 1][cols - 1];
    return max_val;
}

/**
 * 方法二：动态规划 (没有太理解，可以先不看)
 * 上面使用了和棋盘同样大小的数组，这里可以只使用和列数相同的数组大小
 * Reference： https://blog.csdn.net/dugudaibo/article/details/79678890
 */ 
int getMaxValue(const int *values, int rows, int cols) {
    if (values == NULL || rows <= 0 || cols <= 0)
        return 0;
    vector<int> max_vals(cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int left = 0;
            int up = 0;
            if (i > 0)
                up = max_vals[j];
            if (j > 0)
                left = max_vals[j - 1];
            max_vals[j] = max(left, up) + values[i * cols + j];
        }
    }
    int max_val = max_vals[cols - 1];
    return max_val;
}

int main() {
    int values[] = {1, 10, 3, 8,
                    12, 2, 9, 6,
                    5, 7, 4, 11,
                    3, 7, 16, 5};
    int rows = 4, cols = 4;
    cout << getMaxValue(values, rows, cols) << endl;
    return 0;
}