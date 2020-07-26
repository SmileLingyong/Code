/**
 * Creation         :       2019.04.22 16:26
 * Last Reversion   :       2019.04.22 16:46
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * ClimbStairs(爬楼梯问题)
题目描述

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

思路：
   其实就是斐波拉契数列问题（使用动态规划来做）
   第i层台阶，只和第i-1和i-2层台阶有关系，那么从底3层台阶开始，第i层台阶组合 = i-1层台阶组合数 + i-2层台阶组合数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

int ClimbStairs(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int a = 1;
    int b = 2;
    int c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main() {
    int n;
    cin >> n;
    cout << ClimbStairs(n) << endl;
    return 0;
}