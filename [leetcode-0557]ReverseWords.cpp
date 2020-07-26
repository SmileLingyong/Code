/**
 * Creation         :       2019.05.11 10:50
 * Last Reversion   :       2019.05.11 10:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * ReverseWords(反转字符串中的单词 III)
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

string reverseWord(string s) {
    char temp;
    for (int i = 0, j = s.length()-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

/**
 * 方法一：将每个字符提取出来，然后进行逆序
 */ 
string reverseWords(string s) {
    string res = "", cur_str;
    char *s_input = (char *)s.c_str();
    const char *split = " ";
    char *p = strtok(s_input, split);   // 注意，strtok返回的是第一个匹配的分隔符到字符串首的字符串的指针，char *, 这里返回的是"Let's" 
                                        // 原理是通过将第一次找到的分隔符用'\0'替换，然后返回字符串首的指针
    while (p) {
        cur_str = p;
        res += reverseWord(cur_str);
        res += " ";
        p = strtok(NULL, split);  // 返回下一个分隔的字符
    }

    return res.substr(0, res.length()-1);
}

/**
 * 方法二：使用stl模板 reverse
 */ 
string reverseWordsII(string s) {
    size_t front = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || i == s.length()) {
            reverse(&s[front], &s[i]);
            front = i + 1;
        }
    }
    return s;
}

int main() {
    string line;
    getline(cin, line);
    cout << reverseWordsII(line);
    return 0;
}