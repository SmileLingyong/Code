/**
 * Creation         :       2019.07.02 15:20
 * Last Reversion   :       2019.07.02 15:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
divide(两数相除) 
题目描述
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
示例 1:
输入: dividend = 10, divisor = 3
输出: 3

示例 2:
输入: dividend = 7, divisor = -3
输出: -2
说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <math.h>
using namespace std;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000

/**
 * 方法一：不适用乘除法，那就只能利用位运算，使用long类型
 * 计算：A / B = C
 * 最基本的方法，就是每次循环都减一次除数，然后商C++
 * 为了加快运算，我们可以用被除数A每次减去除数最大的2进制倍数，
 * 然后更新A和C，下次A再取除数的最大的2进制倍数，直到A<B，此时的商
 * 就是最后的结果。
 * 举例说明：
 * 比如：40 / 3 = 3*2^3 + 3*2^2 + 3*2^0 + 1;
 * A = 40 - 3 × 2^3 = 40-24 = 16,   C = 0 + 2^3 = 8
 * A = 16 - 3 x 2^2 = 16-12 = 4,    C = 8 + 2^2 = 12
 * A = 4  - 3 x 2^0 = 4 - 3 = 1,    C = 12 + 2^0 = 13
 * 此时 A < B, 输出结果 C = 13
 */ 
int divideII(int dividend, int divisor) {
    // 当除数为0，或者 INT_MIN / -1时，返回最大值
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    long long A = abs((long long)dividend), B = abs((long long)divisor);    // 这里用long long类型来保存结果，防止溢出
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long C = 0;                // 保存最后的商，long long 防止溢出
    while (A >= B) {
        long long temp = B, multiple = 1;
        while (A >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        A -= temp;
        C += multiple;
    }
    return sign == 1 ? C : -C;
}

/**
 * 方法二：不使用long类型 （后面待补充）
 */ 

int main() {
    int A, B;
    cin >> A;
    cin >> B;
    cout << divideII(A, B) << endl;
    return 0;
}