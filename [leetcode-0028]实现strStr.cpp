/**
 * Creation         :       2019.07.01 20:31
 * Last Reversion   :       2019.07.01 20:51
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
strStr(实现strStr()) 
题目描述
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回 -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

/**
 * 获取模式串next数组
 */ 
void GetNext(string str, int next[]) {
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

int KMP(string haystack, string needle, int next[]) {
    int i = 0, j = 0;
    while (i < (int)haystack.size() && j < (int)needle.size()) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == needle.size()) 
        return i - needle.size();
    else 
        return -1;
}

/**
 * 方法一：使用KMP算法
 */ 
int strStr(string haystack, string needle) {
    if (needle.empty())
        return 0;
    int *next = new int[needle.size()];
    GetNext(needle, next);
    return KMP(haystack, needle, next);
}

/**
 * 方法二：使用strStr函数
 */ 
int strStrII(char *haystack, char *needle){
    char *p = strstr(haystack, needle);
    if (p == NULL)
        return -1;
    return p - haystack;
}

int main() {
    string A, B;
    cin >> A;
    cin >> B;
    cout << strStr(A, B) << endl;
    return 0;
}