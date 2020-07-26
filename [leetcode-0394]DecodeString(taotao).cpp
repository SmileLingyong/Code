/**
 * Creation         :       2019.07.03 15:34
 * Last Reversion   :       2019.07.03 15:54
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

思想：
使用DFS思想，自己好好Debug理解一遍（结合剑指offer 17）是一类的题目
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int i;

int is_digist(int x) {
    if (x >= '0' && x <= '9') 
        return 1;
    else
        return 0;
}

string DFS(string s, char left, int ind) {
    string out = "";
    while (ind < s.size()) {
        if (s[ind] == ']') {
            ind++;
            i = ind;
            return out;
        } 
        if (!is_digist(s[ind])) {
            out += s[ind];
            ind++;
        } else {
            // 处理连续字符都是数字
            int times = 0;
            while (is_digist(s[ind])) {
                times = times * 10 + (s[ind++] - '0');
            }
            string res = DFS(s, s[ind], ind+1);
            ind = i;
            for (int j = 0; j < times; j++) {
                for (int k = 0; k < res.size(); k++) {
                    out += res[k];
                }
            }
        }
    }
    return out;
}

/**
 * 方法一：使用DFS思想来做
 */ 
string decodeString(string s) {
    i = 0;
    string out = "";
    while (i < s.length()) {
        if (!is_digist(s[i])) {
            out += s[i];
            i++;
        } else {
            // 处理连续字符都是数字
            int times = 0;
            while (is_digist(s[i])) {
                times = times * 10 + (s[i++] - '0');
            }
            string res = DFS(s, s[i], i+1);
            for (int j = 0; j < times; j++) {
                for (int k = 0; k < res.size(); k++) {
                    out += res[k];
                }
            }
        }
    }
    return out;
}

int main() {
    string s;
    cin >> s;
    cout << decodeString(s) << endl;
    return 0;
}