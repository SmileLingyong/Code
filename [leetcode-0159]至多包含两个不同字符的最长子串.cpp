/**
 * Creation         :       2019.08.18 20:38
 * Last Reversion   :       2019.08.18 20:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
lengthOfLongestSubstringTwoDistinct(至多包含两个不同字符的最长子串)
给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t 。

示例 1:
输入: "eceba"
输出: 3
解释: t 是 "ece"，长度为3。

示例 2:
输入: "ccaabbb"
输出: 5
解释: t 是 "aabbb"，长度为5。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    方法一：滑动窗口 （参考Python版本注释）
*/
int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> str_map;
    int left = 0, right = 0, max_len = 0, counter = 0;
    while (right < s.size()) {
        if (str_map[s[right]] == 0) 
            counter++;
        str_map[s[right]]++;
        right++;
        while (counter > 2) {
            if (str_map[s[left]] == 1) 
                counter--;
            str_map[s[left]] --;
            left ++;
        }
        max_len = max(max_len, right - left);
    }
    return max_len;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}