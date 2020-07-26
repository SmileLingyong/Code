
/**
 * Creation         :       2019.07.03 15:34
 * Last Reversion   :       2019.07.03 15:54
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
DecodeString （字符串解码）
题目描述：
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k
次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
，例如不会出现像 3a 或 2[4] 的输入。

示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

思想：
（结合剑指offer-17, leetcode-394是一类的题目）
括号的题目：
（1）使用栈来做
（2）使用递归
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int is_digist(int x) {
    if (x >= '0' && x <= '9')
        return 1;
    else
        return 0;
}

string decode(string s, int &i) {
    string res = "";
    int n = s.size();
    while (i < n && s[i] != ']') {
        if (!is_digist(s[i])) {
            res += s[i++];
        } else {
            int cnt = 0;
            while (is_digist(s[i])) {
                cnt = cnt * 10 + s[i++] - '0';
            }
            i++;  // 跳过左括号
            string out = decode(s, i);
            i++;  // 跳过右括号
            while (cnt > 0) {
                res += out;
                cnt--;
            }
        }
    }
    return res;
}

/**
 * 方法一：使用递归来做DFS
 */
string decodeString(string s) {
    int i = 0;
    return decode(s, i);
}

/**
 * 方法二：使用栈来做
 * 使用两个栈，一个用来保存个数，一个用来保存字符串。遍历字符串：
 * ①遇到数字，更新cnt；
 * ②遇到左括号，把当前res压入字符串栈中，cnt压入数字串中；
 * ③遇到右括号，取出数字栈顶元素，存入变量k，然后给字符串栈的顶元素循环加上k个res字符串，然后取出栈顶存入res中；
 * ④遇到字母串，直接加入字符串res中即可
 */
string decodeStringII(string s) {
    string res = "";
    stack<int> s_num;
    stack<string> s_str;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt = 10 * cnt + s[i] - '0';
        } else if (s[i] == '[') {
            s_num.push(cnt);
            s_str.push(res);
            cnt = 0;
            res.clear();
        } else if (s[i] == ']') {
            int k = s_num.top();
            s_num.pop();
            for (int j = 0; j < k; j++) {
                s_str.top() += res;
            }
            res = s_str.top();
            s_str.pop();
        } else {
            res += s[i];
        }
    }
    return s_str.empty() ? res : s_str.top();
}

int main() {
    string s;
    cin >> s;
    cout << decodeStringII(s) << endl;
    return 0;
}