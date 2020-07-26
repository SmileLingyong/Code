/**
 * Creation         :       2019.06.23 11:25
 * Last Reversion   :       2019.06.23 11:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * grayCode(格雷编码) 
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:
输入: 2
输出: [0,1,3,2]××××
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1

示例 2:
输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2^n。当 n = 0 时，长度为 2^0 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

思路：
   相当于与剑指offer-12 矩阵路径
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 方法一：使用二进制转换为格雷码的方式
 */ 
vector<int> grayCode(int n) {
    vector<int> res;
    for (int i = 0; i < pow(2, n); i++) {
        res.push_back((i >> 1) ^ i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = grayCode(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}