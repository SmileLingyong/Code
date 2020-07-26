/**
 * Creation         :       2019.07.27 17:58
 * Last Reversion   :       2019.07.27 18:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
generateMatrix （螺旋矩阵 II）
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 从外向内，按照一圈圈的填充元素即可
 */ 
vector<vector<int>> generateMatrix(int n) {
    if (n == 0) return {};
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int l = 0, r = n - 1, t = 0, b = n - 1;
    int num = 1;
    while (l <= r && t <= b) {
        for (int i = l; i <= r; i++) 
            matrix[l][i] = num++;
        for (int i = t + 1; i <= b; i++)
            matrix[i][r] = num++;
        if (t != b) 
            for (int i = r - 1; i >= l; i--) 
                matrix[b][i] = num++;
        if (l != r)
            for (int i = b - 1; i > t; i--)
                matrix[i][l] = num++;
        l++, r--, t++, b--;
    }
    return matrix;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}