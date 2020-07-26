/**
 * Creation         :       2019.05.08 13:48
 * Last Reversion   :       2019.05.08 14:08
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * CountSubstrings(回文子串)
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isPalindrome(string str) {
    for (int i = 0, j = str.length()-1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

int countSubstrings(string s) {
    int count = s.length();
    int cur_len;
    for (cur_len = 2; cur_len <= s.length(); cur_len++) {
        for (int i = 0; (i < s.length()) && (i+cur_len <= s.length()); i++) {
            count += isPalindrome(s.substr(i, cur_len));
        }
    }
    return count;
}

int main() {
    string str;
    cin >> str;
    cout << countSubstrings(str);
    return 0;
}