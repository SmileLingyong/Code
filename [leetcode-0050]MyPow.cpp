/**
 * Creation         :       2019.06.30 20:28
 * Last Reversion   :       2019.06.30 20:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2^(-2) = (1/2)^2 = 1/4 = 0.25
说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

const int int_min = -1 << 31;
const int int_max = 1 << 31 - 1;

double myPow(double x, int n) {
    int flag = 0;
    // 对n取的是负最小值的处理，即比如 x^n = 2^(-2147483648) 时，直接转换为-n = 2147483648 > 2147483647 = int_max，溢出了
    // 对于负的最小值，我们可以先求 (1/x)^(2147483647) * (1/x)
    if (n == int_min) {     
        flag = 1;
        n = n + 1;
    }
        
    if (n < 0) {
        x = 1.0 / x;    
        n = -n;
    }
    double ans = 1;
    double base = x;
    while (n) {
        if (n & 1) {
            ans *= base;
        } 
        base *= base;
        n >>= 1;
    }
    return flag == 1 ? ans * x : ans;
}

int main() {
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << myPow(x, n) << endl;
    return 0;
}