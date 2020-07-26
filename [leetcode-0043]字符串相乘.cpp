/**
 * Creation         :       2019.05.15 16:23
 * Last Reversion   :       2019.05.15 16:
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
multiply(字符串相乘)
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * 方法一：模拟乘法
 * （其实最好还是使用vector来操作）
 */ 
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";
    string res_str = "";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len = num1.size() + num2.size();
    int *res_num = new int[len+1]();  // 后面加个括号就可以初始化为0
    // 手工加法
    for (int i = 0; i < num1.size(); i++) 
        for (int j = 0; j < num2.size(); j++) 
            res_num[i + j] += ((num1[i]-'0') * (num2[j]-'0'));
    // 处理进位
    int pre = 0;
    for (int i = 0; i < len; i++) {
        pre = res_num[i] / 10;
        res_num[i+1] += pre;
        res_num[i] %= 10;
        res_str += to_string(res_num[i]);
    }
    delete [] res_num;
    reverse(res_str.begin(), res_str.end());
    if (res_str[0] == '0')
        res_str.erase(res_str.begin());
    return res_str;
}

/**
 * Todo
 * 方法二：大牛的解法，不用转置来转置去
 */ 

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2);
    return 0;
}