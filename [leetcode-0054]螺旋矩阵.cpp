/**
 * Creation         :       2019.07.27 17:58
 * Last Reversion   :       2019.07.27 17:58
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
spiralOrder（旋转矩阵）
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 从外到内，按照一圈圈的遍历矩阵即可
 */ 
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return {};
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> res;
    int left = 0,  top = 0, right = col - 1, bottom = row - 1;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) 
            res.push_back(matrix[top][i]);
        for (int i = top + 1; i <= bottom; i++) 
            res.push_back(matrix[i][right]);
        if (top != bottom) 
            for (int i = right - 1; i >= left; i--)
                res.push_back(matrix[bottom][i]);
        if (left != right)
            for (int i = bottom - 1; i > top; i--) 
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
    res = spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}