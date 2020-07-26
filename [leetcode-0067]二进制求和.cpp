/**
 * Creation         :       2019.05.15 12:09
 * Last Reversion   :       2019.05.15 12:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
addBinary(二进制求和)
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 　方法一：使用
 */ 
string addBinary(string a, string b) {
    string res = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0, i, dis_len, cur;
    dis_len = a.size() - b.size();
    if (dis_len >= 0) {
        b.append(dis_len, '0');
    } else {
        a.append(-dis_len, '0');
    }
    for (int i = 0; i < a.size(); i++) {
        cur = carry + (a[i] - '0') + (b[i] - '0');
        carry = cur / 2;
        cur %= 2;
        res += to_string(cur);
    }
    if (carry) {
        res += "1";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b);
    return 0;
}