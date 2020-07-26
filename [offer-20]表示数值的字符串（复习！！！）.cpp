/**
 * Creation         :       2019.04:12 20:24
 * Last Reversion   :       2019.04:12 20:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * IsNumeric(表示数值的字符串)
 * 题目描述
 *    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <iostream>
using namespace std;
bool scanInteger(const char **str);
bool scanUnsignedInteger(const char ** str);

/**
 * 扫描可能表示正负的'+'或者'-'为骑士的0~9的数位
 * （类似于一个可能带正负符号的整数），用来匹配前面数值模式中的A和C部分
 */ 
bool scanInteger(const char **str) {
    if (**str == '+' || **str == '-')
        (*str)++;
    return scanUnsignedInteger(str);
}

/**
 * 用来扫描字符串中0~9的数位（类似于一个无符号整数），
 * 可以用来匹配前面数值模式中的B部分。
 */ 
bool scanUnsignedInteger(const char ** str) {
    const char *before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9') 
        (*str)++;
    // 当str中存在若干0~9的数字时，返回true
    return *str > before;
}


/**
 * 数字的格式可以用A[.[B]][e|EC] 或者 .B[e|EC]表示，其中A和C都是整数
 * （可以有正负好，也可以没有），而B是一个无符号整数
 */ 
bool isNumeric(const char *str) {
    if (str == NULL) 
        return false;

    bool numeric = scanInteger(&str);
    // 如果出现'.'，则接下来是数字的小数部分
    if (*str == '.') {
        str++;
        // 下面一行代码用||的原因
        // 1. 小数可以没有整数部分，如.123等于0.123
        // 2. 小数点后面可以没有数字，如233.等于233.0
        // 3. 当然，小数点前面和后面都可以有数字
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    // 如果出现'e'或者'E'，则接下来是数字的指数部分
    if (*str == 'e' || *str == 'E') {
        str++;
        // 下面一行代码用&&的原因
        // 1. 当e或者E前面没有数字时，整个字符串不猛表示数字，如.e1、e1;
        // 2. 当e或E后面没有整数时，真个字符串不能表示数字，如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }
    return numeric && *str == '\0';
}

int main() {
    string str;
    cin >> str;
    if (isNumeric(str.c_str())) {
        cout << "Is Numeric!" << endl;
    } else {
        cout << "Isn't Numeric!" << endl;
    }
    return 0;
}