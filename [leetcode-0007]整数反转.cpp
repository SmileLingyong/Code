/**
 * Creation         :       2019.05.14 23:16
 * Last Reversion   :       2019.05.14 23:16
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * reverse(整数反转)
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31−1]。
请根据这个假设，如果反转后整数溢出那么就返回 0。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>
using namespace std;
const int MAX_INT32 = 2147483647;
const int MIN_INT32 = -2147483648;

/**
 * 方法一：使用栈，将每一位存储起来，然后逆序乘10累加得到反转的结果
 * 方法二：可以直接不适用栈，出来以为就加上一位。
 * 
 * 弊端：整数太大，超过int所能表示的范围，溢出问题，需要返回0
 * 分析 int32 取值范围为（–214748364 <= x <= 2147483647）
 * 所以，我们只需要判断结果是否在这个区间范围内就行，考虑最大的x输入，
 * 那么x的第一位只能是1或者2，翻转之后res的最后一位只能是1或2，所以
 * res只能是 2147483641 或 2147483642都在int的范围内。但是它们
 * 对应的x为 1463847412 和 2463847412，后者超出了数值范围。所以
 * 当过程中res等于 214748364 时， 输入的x只能为 1463847412，
 * 翻转后的结果为 2147483641，都在正确的范围内，所以不用check。
 */ 
int reverse(int x) {
    int res = 0;
    while (x) {
        if (abs(res) > MAX_INT32 / 10) return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
/**
 * 方法二：
 * 使用long long类型，防止保存结果溢出，如果超过int范围，则返回0
 */ 
int reverseII(int x) {
    long long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < MIN_INT32 || res > MAX_INT32) ? 0 : res;
}

int main() {
    int x;
    cin >> x;
    cout << reverseII(x);
    return 0;
}
