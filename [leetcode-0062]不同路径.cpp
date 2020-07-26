/**
 * Creation         :       2019.07.16 21:00
 * Last Reversion   :       2019.07.16 21:16
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
uniquePaths（不同路径）
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？

说明：m 和 n 的值均不超过 100。
示例 1:
输入: m = 3, n = 2
输出: 3

解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 2:
输入: m = 7, n = 3
输出: 28
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法二：动态规划
 * （1）定义状态： dp[i][j]：到达 i, j 的最多路径
 * （2）动态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 注意：对于第一行 dp[0][j]，或者是第一列 dp[i][0]，由于都是再边界，所以只能为1
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(m * n)
 * 优化：因为我们每次只需要 dp[i-1][j],dp[i][j-1]
 */
int uniquePathsII(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int Moving(int x, int y, int rows, int cols) {
    int sum = 0;
    if (x == rows - 1, y == cols - 1) {
        return 1;
    }
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        sum = sum + Moving(x + 1, y, rows, cols) 
                  + Moving(x, y + 1, rows, cols);
    }
    return sum;
}

/**
 * 方法一：DFS深度优先搜索
 * 时间复杂度：
 * 空间复杂度：
 * 严重超时！
 */
int uniquePaths(int m, int n) { 
    return Moving(0, 0, m, n); 
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePathsII(m, n) << endl;
    cout << uniquePaths(m, n) << endl;
    return 0;
}
