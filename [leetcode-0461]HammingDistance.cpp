/**
 * Creation         :       2019.05.09 21:23
 * Last Reversion   :       2019.05.09 21:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * hammingDistance(汉明距离总和)
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 2^31.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 查看 LeetCode0477 解答
 */ 
int hammingDistance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    while (z) {
        count++;
        z &= (z - 1);
    }
    return count;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y);
    return 0;
}