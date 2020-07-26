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
#include <iostream>
#include <cstring>  // 代表C语言中的string.h库(C++新标准用模板类实现的，包含字符串处理函数)。这样写目的是命名规范更符合C++, 
                    // 并且cname的头文件中定义的名字从属于命名空间std. 而定义在名为.h的头文件中则不然
#include <string>   // 标准C++库，定义了标准std::string类，属于STL范畴
using namespace std;

#define MAX_SIZE 1000
/**
 * 思想：
 *    当矩阵坐标中为(row, col)的格子和路径字符串中下标为pathLength的字符串一样时，并且
 * 该格子未被访问时，则从4个相邻的格子(row, col-1)、(row, col+1)、(row-1, col)、(row+1, col)
 * 中去定位路径字符串中下标为pathLength+1的字符。
 *    如果4个相邻的格子都没有匹配字符串中下标为pathLength+1的字符，则表明当前路径字符串中
 * 下标为pathLength的字符在矩阵中定位不正确，我们需要回到前一个字符(pathLength-1)，然后重新定位。
 *    一直重复这个过程，知道路径字符串上的所有字符都在矩阵中找到合适的位置（此时 str[pathLength] == '\0'）
 */ 
bool Judge(const char *matrix, int rows, int cols, int row, int col, 
                const char *str, int& pathLength, bool *visited) {
    if (str[pathLength] == '\0')                    // 遍历完路径字符串，说明路径字符串上的所有字符都在矩阵中找到合适的位置了
        return true;
    
    bool hasPath = false;
    int index = row * cols + col;  
    if (row >= 0 && row < rows && col >= 0 && col < cols 
            && matrix[index] == str[pathLength]
                && !visited[index]) {    // str[pathLength]字符找到了
        ++pathLength;                    // 继续找下一个
        visited[index] = true;           // 并将找到的这个矩阵元素标识为已访问
        hasPath = Judge(matrix, rows, cols, row, col-1, str, pathLength, visited)
               || Judge(matrix, rows, cols, row, col+1, str, pathLength, visited)  
               || Judge(matrix, rows, cols, row-1, col, str, pathLength, visited) 
               || Judge(matrix, rows, cols, row+1, col, str, pathLength, visited);
        if (!hasPath) {                 
            --pathLength;
            visited[index] = false;
        }
    }
    return hasPath;
}

bool hasPath(char *matrix, int rows, int cols, char *str) {
    if (matrix == NULL || rows < 1 || cols < 1 || str == NULL) 
        return false;
    bool *visited = new bool[rows * cols];  // 创建一个bool类型的动态数组，返回数组的第一个元素类型的指针
    memset(visited, 0, rows * cols);        // 将bool数组元素都初始化为0，即false

    int pathLength = 0;                     // 路径字符串下标
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (Judge(matrix, rows, cols, row, col, str, pathLength, visited)) {
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}

int main() {
    char matrix[MAX_SIZE], str[MAX_SIZE];
    int rows, cols, res;
    printf("Please input the row number:\n");
    scanf("%d", &rows);
    printf("Please input the col number:\n");
    scanf("%d", &cols);
    getchar();                  // 读取缓冲区中的回车
    printf("Please input the matrix:\n");
    scanf("%s", matrix);        // 或者直接使用 scanf("%s", matrix); 更加方便，如果不存在字符串中有空格的情况
    printf("Please input the search path:\n");
    getchar();                  // 读取缓冲区中的回车
    scanf("%s", str);
    res = hasPath(matrix, rows, cols, str);
    if (res) {
        printf("Matirx has this path!\n");
    } else {
        printf("Matirx do not has this path!\n");
    }
    // getchar();
    return 0;
}