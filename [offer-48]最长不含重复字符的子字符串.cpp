/**
 * Creation         :       2019.07.10 11:26
 * Last Reversion   :       2019.07.10 11:26
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
LongestSubStirng(最长不含重复字符的子字符串) leetcode-03
题目描述：
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
假设字符串中只包含'a' ~ 'z' 的字符。例如，在字符串"arabcacfr"中，最长的不含
重复字符的子字符串是"acfr"，长度为4
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/**
 * 方法一：常规方法，不断往后遍历即可
 * 时间复杂度： O(n^3)
 * 子串有 O(n^2)，然后还要 O(n)的时间判断一个字符串中是否包含重复字符
 */ 
int LongestSubString(string str) {
    int max_len = 0, cur_len, now;
    set<char> cur_str;
    for (int i = 0; i < str.size(); i++) {
        cur_str.clear();
        cur_len  = 0;
        now = i;
        while (i < str.size() && cur_str.find(str[i]) == cur_str.end()) {
            cur_str.insert(str[i]);
            cur_len++;
            i++;
        }
        max_len = max(max_len, cur_len);
        i = now;
    }
    return max_len;
}

/**
 * 方法二：滑动窗口
 * 定义一个map数据结构，存储(k, v)，其中key值为字符，value值为该key值下一个不重复的位置，即当前位置 + 1
 * 定义不重复子串开始位置为 start，结束位置为 end
 * 随着 end 不断遍历向后，会遇到与 [start, end] 区间内字符相同的字符，此时将字符做为key，获取其对应value值，
 * 来更新 start，此时 [start, end]，此时 [start, end] 区间内不存在重复字符
 * map 和 结果 res 会在每次遍历的同时更新 
 * （结合下面的动态图，自己理解一遍即可）
 * Reference: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-jie-suan-fa-3-wu-zhong-fu-zi-fu-de-zui-chang-z/
 */ 
int LongestSubStringII(string str) {
    int char_map[256] = {0}, res = 0, start = 0;
    for (int end = 0; end < str.size(); end++) {
        if (char_map[str[end]] != 0) {
            start = max(start, char_map[str[end]]);
        }
        res = max(res, end - start + 1);
        char_map[str[end]] = end + 1;
    }
    return res;
}



int main() {
    string str;
    cin >> str;
    cout << LongestSubString(str) << endl;
    return 0;
}