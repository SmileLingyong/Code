/**
 * Creation         :       2019.07.05 20:10
 * Last Reversion   :       2019.07.05 20:28
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
Rotate (旋转数组)
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
示例 1:
给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：先转置，然后再翻转两列：时间复杂度：O(n^2)
 * [1,2,3],   转置    [1,4,7],   翻转列   [7,4,1],
 * [4,5,6],  —————>  [2,5,8],  ———————> [8,5,2],
 * [7,8,9]           [3,6,9]            [9,6,3]
 */
void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();  // 这里由于是方阵，所以 row == col
    int col = matrix[0].size();
    int temp;
    // 先转置
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // 然后对称列翻转
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][col - j - 1];
            matrix[i][col - j - 1] = temp;
        }
    }
}

/**
 * 方法二：将矩形由外向内，每一圈的4条边的元素进n行循环交换，看看题解的示意图就明白了
 */
void rotateII(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int temp;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            temp = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // rotate(matrix);
    rotateII(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}