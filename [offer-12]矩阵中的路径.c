/**
 * Creation         :       2019.04.03 09:22
 * Last Reversion   :       2019.03.03 11:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * HasPath(矩阵中的路径)
 * 题目描述
 *    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符
 * 的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，
 * 向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能
 * 再次进入这个格子。 例如 abcesfcsadee 这样的3 X 4 矩阵中包
 * 含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一
 * 个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
   输入：
        3
        4
        abcesfcsadee
        bcced
        abcb
   输出：
        1
        0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>     // 头文件定义了一个变量类型、一个宏和各种操作字符数组的函数。
#include <stdlib.h>     // 头文件定义了四个变量类型、一些宏和各种通用工具函数

#define MAX_SIZE 1000

/**
 * 这个函数和下面的是等价的
 */ 
int Judge2(const char *matrix, int rows, int cols, int row, int col, 
                const char *str, int pathLength, int *visited) {
    if (str[pathLength] == '\0')                    // 遍历完路径字符串，说明路径字符串上的所有字符都在矩阵中找到合适的位置了
        return 1;
    
    int hasPath = 0;
    int index = row * cols + col;    
    if (row >= 0 && row < rows && col >= 0 && col < cols 
            && matrix[index] == str[pathLength]
                && !visited[index]) {               // str[pathLength]字符找到了
        visited[index] = 1;                         // 并将找到的这个矩阵元素标识为已访问
        hasPath = Judge(matrix, rows, cols, row, col-1, str, pathLength+1, visited)
               || Judge(matrix, rows, cols, row, col+1, str, pathLength+1, visited)  
               || Judge(matrix, rows, cols, row-1, col, str, pathLength+1, visited) 
               || Judge(matrix, rows, cols, row+1, col, str, pathLength+1, visited);
        if (!hasPath) {                 
            visited[index] = 0;
        }
    }
    return hasPath;
}

/**
 * 思想：
 *    当矩阵坐标中为(row, col)的格子和路径字符串中下标为pathLength的字符串一样时，并且
 * 该格子未被访问时，则从4个相邻的格子(row, col-1)、(row, col+1)、(row-1, col)、(row+1, col)
 * 中去定位路径字符串中下标为pathLength+1的字符。
 *    如果4个相邻的格子都没有匹配字符串中下标为pathLength+1的字符，则表明当前路径字符串中
 * 下标为pathLength的字符在矩阵中定位不正确，我们需要回到前一个字符(pathLength-1)，然后重新定位。
 *    一直重复这个过程，知道路径字符串上的所有字符都在矩阵中找到合适的位置（此时 str[pathLength] == '\0'）
 */ 
int Judge(const char *matrix, int rows, int cols, int row, int col, 
                const char *str, int pathLength, int *visited) {
    if (str[pathLength] == '\0')                    // 遍历完路径字符串，说明路径字符串上的所有字符都在矩阵中找到合适的位置了
        return 1;
    
    int hasPath = 0;
    int index = row * cols + col;    
    if (row >= 0 && row < rows && col >= 0 && col < cols 
            && matrix[index] == str[pathLength]
                && !visited[index]) {               // str[pathLength]字符找到了
        visited[index] = 1;                         // 并将找到的这个矩阵元素标识为已访问
        pathLength++;                               // 继续找下一个
        hasPath = Judge(matrix, rows, cols, row, col-1, str, pathLength, visited)
               || Judge(matrix, rows, cols, row, col+1, str, pathLength, visited)  
               || Judge(matrix, rows, cols, row-1, col, str, pathLength, visited) 
               || Judge(matrix, rows, cols, row+1, col, str, pathLength, visited);
        if (!hasPath) {                 
            visited[index] = 0;
            pathLength--;
        }
    }
    return hasPath;
}

int hasPath(char *matrix, int rows, int cols, char *str) {
    if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) 
        return 0;
    int *visited = (int*)malloc(sizeof(int) * rows * cols); // 创建一个int类型的动态数组，注意一定要与free()成对使用
    for (int i = 0; i < rows * cols; i++)                   // 初始化标志数组，不能用 memset(visited, 0, rows * cols); 没有用！！！被这个坑了
        *(visited+i) = 0;
    // int visited[rows][cols] = {0};                       // 或者直接通过这一条语句定义并初始化
    int pathLength = 0;                                     // 路径字符串下标
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (Judge(matrix, rows, cols, row, col, str, 0, visited)) {     // 可以直接传入0，表示从matrix矩阵第一个位置开始遍历，结合八皇后问题一起理解
                return 1;
            }
        }
    }
    free(visited);  
    return 0;
}

int main() {
    char matrix[MAX_SIZE], str[MAX_SIZE];
    int rows, cols, res;
    printf("Please input the row number:\n");
    scanf("%d", &rows);
    printf("Please input the col number:\n");
    scanf("%d", &cols);
    getchar();          // 读取缓冲区中的回车
    printf("Please input the matrix:\n");
    gets(matrix);       // 或者直接使用 scanf("%s", matrix); 更加方便，如果不存在字符串中有空格的情况
    printf("Please input the search path:\n");
    // getchar();          // 读取缓冲区中的回车
    gets(str);
    res = hasPath(matrix, rows, cols, str);
    if (res) {
        printf("Matirx has this path!\n");
    } else {
        printf("Matirx do not has this path!\n");
    }
    getchar();
    return 0;
}