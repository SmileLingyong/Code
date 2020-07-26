/**
 * Creation         :       2019.08.18 20:38
 * Last Reversion   :       2019.08.18 20:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
minWindow(最小覆盖子串)
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    方法一：使用滑动窗口，左右指针，套用模板 （和python版本对应）
    （1）使用双指针，初始化 left = right = 0, 把索引闭区间 [left, right] 称为窗口
    （2）先不断的增加right指针，扩大窗口 [left, right]，同时记录当前窗口中每个字符出现的次数，
        直到窗口中的字符串符合要求（包含了T中的所有字符）
    （3）此时，我们停止增加right，转而不断增加left指针，缩小窗口[left, right]，
        直到窗口中的字符串不再符合要求（不包含T中的所有字符了）。同时，每次增加left，我们都要更新一轮结果
    （4）重负第2和第3步，直到right达到字符串S的末尾
    【第2步相当于在寻找一个可行解，然后第3步在优化这个可行解，最终找到最优解。指针轮流前进，窗口大小增增减减，窗口不断向右滑动】
ADOBECODEBANC
ABC    
*/
string minWindow(string s, string t) {
    string res = "";
    unordered_map<char, int> str_map;
    int left = 0, right = 0, min_len = 0x7fffffff, counter = 0;
    for (char c : t) str_map[c]++;
    while (right < s.size()) {
        if (str_map[s[right]] > 0) 
            counter++;
        str_map[s[right]]--;
        right ++;
        while (counter == t.size()) {
            if (min_len > right - left) {
                min_len = right - left;
                res = s.substr(left, min_len);
            }
            if (str_map[s[left]] == 0) {
                counter--;
            }
            str_map[s[left]]++;
            left++;
        }
    }
    return res;
}

/*
    优化版本
*/
string minWindowII(string s, string t) {
    string res = "";
    unordered_map<char, int> str_map;
    int left = 0, cnt = 0, min_len = 0x7fffffff;
    for (char c : t) str_map[c]++;
    for (int right = 0; right < s.size(); right++) {
        if (--str_map[s[right]] >= 0) cnt++;
        while (cnt == t.size()) {
            if (min_len > right - left + 1) {
                min_len = right - left + 1;
                res = s.substr(left, min_len);
            }
            if (++str_map[s[left]] > 0) cnt--;
            left ++;
        }
    }
    return res;
}

int main() {
    string S, T;
    cin >> S;
    cin >> T;
    cout << minWindow(S, T) << endl;
    return 0;
}