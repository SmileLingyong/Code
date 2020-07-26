/**
 * Creation         :       2019.08.18 20:38
 * Last Reversion   :       2019.08.18 20:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
lengthOfLongestSubstringKDistinct(至多包含K个不同字符的最长子串)
给定一个字符串 s ，找出 至多 包含k个不同字符的最长子串 t 。

示例 1:
输入: "eceba" 2
输出: 3
解释: t 是 "ece"，长度为3。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    方法一：滑动窗口（参考leetcode-159）
*/
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> str_map;
    int left = 0, right = 0, counter = 0, max_len = 0;
    while (right < s.size()) {
        if (str_map[s[right]] == 0)
            counter ++;
        str_map[s[right]] ++;
        right ++;
        while (counter > k) {
            if (str_map[s[left] == 1])
                counter--;
            str_map[s[left]]--;
            left ++;
        }
        max_len = max(max_len, right - left);
    }
    return max_len;
}


int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    cout << lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}