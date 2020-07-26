/**
 * Creation         :       2019.07.01 14:28
 * Last Reversion   :       2019.07.01 14:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * shortestPalindrome(最短回文串) 
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:
输入: "aacecaaa"
输出: "aaacecaaa"

示例 2:
输入: "abcd"
输出: "dcbabcd"
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 方法一：递归
 * 我们使用双指针来找出字符串s的最长回文前缀的大概范围，指针i和j分别指向s串的开头和末尾，
 * 若 s[i] 和 s[j] 相等，则i自增1，j自减1，否则只有j自减1。这样遍历一遍后，最长回文
 * 前缀就在范围 [0, i) 中，但不保证这个本身就是最大回文前缀，我们只能确定后面剩余的部分
 * 肯定不属于，此时我们提取出剩下的字符，翻转一下加到最前面，而对范围 [0, i) 内的子串再
 * 次递归调用本函数，这样，在子函数最终会组成最短的回文串，从而使得整个的回文串就是最短的
 */ 
string shortestPalindrome(string s) {
    int i = 0, n = s.size();
    for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j]) i++;
    }
    if (i == n)                         // 此时s串本身就是回文串
        return s;
    string rem = s.substr(i);           // 截取s串 i到之后的部分
    reverse(rem.begin(), rem.end());    // 翻转一下加到最前面
    // 而对范围 [0, i) 内的子串再次递归调用本函数，这样，在子函数最终会组成最短的回文串，从而使得整个的回文串就是最短的
    return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
}


/**
 * 计算next数组
 */ 
void GetNext(string &str, vector<int> &next) {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < str.size()) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/**
 * 方法二：使用KMP的思想
 */ 
string shortestPalindromeII(string s) {
    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());
    string str = s + "#" + r;
    vector<int> next(2 * n + 2);
    GetNext(str, next); // 由于next[i]保存的是str[0-i]前面和后面匹配的字符串长度，这样next[2*n+1]就保存了s中最长的回文子串长度
    // 比如 s = "aacecaaa"
    // str = s + "#" + r = "aacecaaa#aaacecaa"，最长的回文子串长度就为next[2*n+1]=next[17]=7
    // 所以末尾的 r.substr(0,n-7) = "a"就是我们需要添加到s前面的剩余字符
    return r.substr(0, n - next[2 * n + 1]) + s;
}

int main() {
    string str;
    cin >> str;
    cout << "最短回文子串为：\n" << shortestPalindrome(str) << endl;
    cout << "最短回文子串为：\n" << shortestPalindromeII(str) << endl;
    return 0;
}