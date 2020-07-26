/**
 * Creation         :       2019.04:12 21:20
 * Last Reversion   :       2019.04:12 21:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
PrintMatrix(顺时针打印矩阵)
题目描述
   输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
思路：
   相当于一圈一圈打印矩阵
-----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 从外到内，按照一圈圈的遍历矩阵即可
 */ 
vector<int> printMatrix(vector<vector<int> > matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> res;

    // 输入的二维数组非法，返回空的数组
    if (row == 0 || col == 0)
        return res;
    // 定义四个关键变量，表示左上和右下的打印范围，自己画个图就明白了
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    while (left <= right && top <= bottom) {
        // left to right
        for (int i = left; i <= right; i++) 
            res.push_back(matrix[top][i]);
        // top to bottom
        for (int i = top+1; i <= bottom; i++) 
            res.push_back(matrix[i][right]);
        // right to left
        if (top != bottom)  // 如果该圈不止一行，才需要right to left
            for (int i = right-1; i >= left; i--) 
                res.push_back(matrix[bottom][i]);
        // bottom to top
        if (left != right)  // 如果该圈不止一列，才需要bottom to top
            for (int i = bottom-1; i > top; i--)    // 注意这里是 > top
                res.push_back(matrix[i][left]); 
        left++, top++, right--, bottom--;
    }
    return res;
}

int main() {
    vector<vector<int> > matrix;
    vector<int> res;
    int n, m, input;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        for (int j = 0; j < m; j++) {
            cin >> input;
            arr.push_back(input);
        }
        matrix.push_back(arr);
    }
    res = printMatrix(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}