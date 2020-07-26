/**
 * Creation         :       2019.07.17 13:26
 * Last Reversion   :       2019.07.17 13:37
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
uniquePathsWithObstacles（最小路径和）
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
using namespace std;

/**
    方法一：动态规划
    (1)定义状态：dp[i][j]：表示到[i, j]位置时的最小路径和
    (2)状态转移方程： dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
    (3)递归出口：初始化 dp[i][j] = 0 值全为0
 */ 
int minPathSum(vector<vector<int>>& grid) {
    int rows, cols;
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < cols; j++) 
        dp[0][j] = dp[0][j-1] + grid[0][j];
    for (int i = 1; i < rows; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[rows-1][cols-1];
}

int main() {
    vector<vector<int>> grid(3, vector<int>(3, 0));
    grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}