/**
 * Creation         :       2019.05.15 16:11
 * Last Reversion   :       2019.05.15 16:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * addStrings(字符串相加)
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) {
    string res = "";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry = 0, i, dis_len, cur;
    dis_len = num1.size() - num2.size();
    if (dis_len >= 0) {
        num2.append(dis_len, '0');
    } else {
        num1.append(-dis_len, '0');
    }
    for (i = 0; i < num1.size(); i++) {
        cur = carry + (num1[i] - '0') + (num2[i] - '0');
        carry = cur / 10;
        cur %= 10;
        res += to_string(cur);
    }
    if (carry) {
        res += "1";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2);
    return 0;
}