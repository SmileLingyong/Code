/**
 * Creation         :       2019.08.16 00:44
 * Last Reversion   :       2019.08.16 00:44
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
三维形体的表面积
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。
 
示例 1：
输入：[[2]]
输出：10

示例 2：
输入：[[1,2],[3,4]]
输出：34

示例 3：
输入：[[1,0],[0,2]]
输出：16

示例 4：
输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32

示例 5：
输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46

提示：
1 <= N <= 50
0 <= grid[i][j] <= 50
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count += grid[i][j] * 6;
            if (grid[i][j] >= 2) 
                count -= (grid[i][j] - 1) * 2;
            if (j > 0)
                count -= min(grid[i][j], grid[i][j-1]) * 2;
            if (i > 0)
                count -= min(grid[i][j], grid[i-1][j]) * 2;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << surfaceArea(nums);
    return 0;
}