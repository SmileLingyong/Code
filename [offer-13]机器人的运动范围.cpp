/**
 * Creation         :       2019.04.05 00:08
 * Last Reversion   :       2019.04.05 09:56
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
MovingCount(机器人的运动范围)
题目描述
   地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，每一次只能
向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k
的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

思路：
   回溯的思想（类似于DFS深度优先搜索,先序遍历）
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 计算整数各位之和
 */
int GetDigistSum(int number) {
    int sum = 0;
    while (number) {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

/**
 * DFS 深度优先遍历
 */ 
int Moving(int threshold, int rows, int cols, int x, int y, int *visited) {
    int count = 0;
    if (x >= 0 && x < rows && y >= 0 && y < cols 
            && (GetDigistSum(x) + GetDigistSum(y)) <= threshold 
                && visited[x * cols + y] == 0) {
        visited[x * cols + y] = 1;
        count = 1 + Moving(threshold, rows, cols, x-1, y, visited)
                  + Moving(threshold, rows, cols, x+1, y, visited)
                  + Moving(threshold, rows, cols, x, y-1, visited)
                  + Moving(threshold, rows, cols, x, y+1, visited);
        // 注意，这里要统计的是能走多少个格子，所以不能把之前走过的回溯成未标记，即没有 visited[index] = 1; 这句
    }
    return count;
}

/**
 * 初始化访问标志矩阵，并从 (0, 0) 开始遍历
 */ 
int MovingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows < 0 || cols < 0)
        return 0;
    int *visited = (int*)malloc(sizeof(int) * rows * cols);
    for (int i = 0; i < rows * cols; i++) 
        *(visited + i) = 0;
    int count = Moving(threshold, rows, cols, 0, 0, visited);
    free(visited);
    return count;
}

int main() {
    int rows, cols, threshold = 18;
    scanf("%d %d", &rows, &cols);
    scanf("%d", &threshold);
    printf("%d\n", MovingCount(threshold, rows, cols));
    return 0;
}