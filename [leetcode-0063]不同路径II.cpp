/**
 * Creation         :       2019.07.17 10:48
 * Last Reversion   :       2019.07.17 10:48
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
uniquePathsWithObstacles（不同路径II）
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。
示例 1:
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;
/**
 * 动态规划
 */ 
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m, n;
    m = obstacleGrid.size();
    n = obstacleGrid[0].size();
    if (obstacleGrid[m-1][n-1] == 1)                            // 如果终点是障碍物，则返回0
        return 0;
    vector<vector<long long>> dp(m, vector<long long>(n, 0));   // dp全初始化为0
    dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;     // 将第一个元素dp[0][0] 标记，不是障碍为0，否则为1
    for (int j = 1; j < n; j++)                                 // 遍历第一行，如果为障碍物，则dp对应标记为0，否则标记为前一个dp元素，画图很容易理解    
         dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j-1];
    for (int i = 1; i < m; i++)                                 // 遍历第一行，如果为障碍物，则dp对应标记为0，否则标记为前一个dp元素，画图很容易理解
        dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i-1][0];
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1)                        // 从dp[1][1]开始遍历，如果只有一行的话，就不会执行进来 
                dp[i][j] = 0;                                   // 当前是障碍物,则dp对应为0
            else    
                dp[i][j] = dp[i-1][j] + dp[i][j-1];             // 当前不是障碍物，则为左 + 上之和
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // matrix = {{1, 0}};
    cout << uniquePathsWithObstacles(matrix) << endl;
    return 0;
}