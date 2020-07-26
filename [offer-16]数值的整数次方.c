/**
 * Creation         :       2019.04.08 14:26
 * Last Reversion   :       2019.04.08 14:48
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
Power(数值的整数次方)
题目描述
   给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
思路：
   快速幂
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <math.h>

double Power(double base, int exponent) {
    if (base == 0)                      // 底数为0的情况
        return 0;
    if (exponent == 0)                  // 指数为0的情况
        return 1;
    int e = abs(exponent);              // 处理指数为负数情况
    double ans = 1;
    while (e) {
        if (e & 1) {
            ans *= base;
        }
        base *= base;
        e >>= 1;                        // b左移一位，即相当于b /= 2;
    }
    return exponent < 0 ? 1/ans : ans;  // 处理指数为负数情况
}

int main() {
    double a;
    int n;
    scanf("%lf %lf", &a, &n);                       // 注意double类型输入要用%lf 
    printf("%lf^%lf = %lf\n", a, n, Power(a, n));   // 注意double类型输出用%f或%lf都行，因为在执行时，C自动将float型的参数转换成double型。
    return 0;
}