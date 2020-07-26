/**
 * Creation         :       2019.06.30 20:28
 * Last Reversion   :       2019.06.30 20:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
Pow(x, n)
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;


/**
 * 方法一：使用二分法，不断缩小范围，直到找到第一个平方大于x的数
 * 自己手动debug一下就明白
 */ 
int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 0, right = x;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x / mid >= mid) 
            left = mid + 1;
        else 
            right = mid;
    }
    return right - 1;
}



int main() {
    int n;
    cin >> n;

    return 0;
}