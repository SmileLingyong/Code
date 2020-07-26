/**
 * Creation         :       2019.05.08 10:47
 * Last Reversion   :       2019.05.08 10:47
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
LengthOfLongestSubstring（无重复字符的最长子串）
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"

输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
方法一：滑动窗口（其实和自己写的方法是一样的）
什么是滑动窗口？
其实就是一个队列,比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，
当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！

如何移动？
我们只要把队列的左边的元素移出就行了，直到满足题目要求！
一直维持这样的队列，找出队列出现最长的长度时候，求出解！
时间复杂度：O(n)O(n)
*/
int lengthOfLongestSubstring(string str) {
    if (str.size() == 0) return 0;
    unordered_set<char> lookup;
    int max_len = 0;
    int left = 0;
    for (int i = 0; i < str.size(); i++) {
        while (lookup.find(str[i]) != lookup.end()) {   // 当前为重复元素
            lookup.erase(str[left]);
            left ++;
        }
        max_len = max(max_len, i - left + 1);
        lookup.insert(str[i]);
    }
    return max_len;
}

/**
 * 方法二：常规方法，不断往后遍历即可
 * 时间复杂度： O(n^3)
 * 子串有 O(n^2)，然后还要 O(n)的时间判断一个字符串中是否包含重复字符
 */ 
int lengthOfLongestSubstringIII(string str) {
    int max_len = 0, cur_len, start = 0, now;
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
 * 方法三：滑动窗口法　（不好记忆，还不如上面的方法）
 * 定义一个map数据结构，存储(k, v)，其中key值为字符，value值为该key值下一个不重复的位置，即当前位置 + 1
 * 定义不重复子串开始位置为 start，结束位置为 end
 * 随着 end 不断遍历向后，会遇到与 [start, end] 区间内字符相同的字符，此时将字符做为key，获取其对应value值，
 * 来更新 start，此时 [start, end]，此时 [start, end] 区间内不存在重复字符
 * map 和 结果 res 会在每次遍历的同时更新 
 * （结合下面的动态图，自己理解一遍即可）
 * Reference: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-jie-suan-fa-3-wu-zhong-fu-zi-fu-de-zui-chang-z/
 */ 
int lengthOfLongestSubstringII(string s) {
    int char_map[256] = {0}, res = 0, start = 0;
    for (int end = 0; end < s.size(); end++) {
        if (char_map[s[end]] != 0) {
            start = max(char_map[s[end]], start);
        }
        res = max(res, end - start + 1);
        char_map[s[end]] = end + 1;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;
    cout << lengthOfLongestSubstringII(str) << endl;
    cout << lengthOfLongestSubstringII(str) << endl;
    return 0;
}