/**
 * Creation         :       2019.07.26 14:56
 * Last Reversion   :       2019.07.26 14:56
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
StrToInt (把字符串转换成整数)
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符
合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个
合法的数值则返回0。

输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
+2147483647
    1a33

输出
2147483647
    0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
using namespace std;

const int INT_32_MIN = -0x80000000;  // -2147483648
const int INT_32_MAX = 0x7fffffff;   //  2147483647

/**
 * 方法一：对第一位进行判断，看其是否是符号位，然后对后面的数字不断计算即可，若后面出现了不是数字的字符，则返回0
 * 注意：这里没有做溢出判断
 */ 
int StrToInt(string str) {
    if (str.empty()) return 0;
    int length = str.size();
    int sum = 0, i = 0, sign = 1;
    if (str[0] == '+' || str[0] == '-') {
        if (str[0] == '-')
            sign = -1;
            i++;
    }
    for (; i < length; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            sum = sum * 10 + (str[i] - '0');
        } else {
            return 0;
        }
    }
    return sign * sum;
}

int main() {
    string str;
    getline(cin, str);
    cout << StrToInt(str) << endl;
    return 0;
}