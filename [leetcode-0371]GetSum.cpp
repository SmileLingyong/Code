/**
 * Creation         :       2019.05.15 11:47
 * Last Reversion   :       2019.05.15 11:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * getSum(两整数之和)
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:
输入: a = 1, b = 2
输出: 3

示例 2:
输入: a = -2, b = 3
输出: 1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;
const int max_num = 0x7777777;  // 16进制表示的是第32位为0，后面都为1的二进制，即表示32位int类型最高位为0，后面全为1的数

/**
 * 方法一：递归，使用位操作
 * 不使用加减法，则使用位操作。分析： 759+674
 * 1. 如果我们不考虑进位，可以得到 323
 * 2. 如果我们只考虑进位，可以得到 1110
 * 3. 我们把上面两个数字假期 323+1110=1433 就是最终结果了
 * 然后我们进一步分析，如果得到上面的第一第二种情况，我们在二进制下来看，
 * 不考虑进位的加，0+0=0，0+1=1, 1+0=1，1+1=0，这就是异或的运算规则，
 * 如果只考虑进位的加 0+0=0, 0+1=0, 1+0=0, 1+1=1，而这其实这就是'与'的运算，
 * 而第三步在将两者相加时，我们再递归调用这个算法，终止条件是当进位为0时，直接返
 * 回第一步的结果。OJ比较严格，不能对负数进行左移，就是说最高位符号位必须要为0，才能左移
 * 那么我们在a和b相'与'之后，再'与'上一个最高位为0，其余位都为1的数 0x7fffffff，这样
 * 可以强制将最高位清零，然后再进行左移，完美解决问题。
 */ 
int getSum(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b & 0x7fffffff) << 1;
    return getSum(sum, carry);
}

/**
 * 方法二：精简到一行
 */ 
int getSumII(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (a & b & 0x7fffffff) << 1);
}

/**
 * 方法三：迭代求法
 */ 
int getSumIII(int a, int b) {
    while (b) {
        int carry = (a & b & 0x7fffffff) << 1; // 这里将进位与上0x7777777，保证a & b的结果为正数，即最高位为0，才能 << 左移
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << getSumIII(a, b);
    return 0;
}