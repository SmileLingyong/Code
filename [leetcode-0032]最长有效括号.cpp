/**
 * Creation         :       2019.07.11 00:01
 * Last Reversion   :       2019.07.11 00:01
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
longestValidParentheses (最长有效括号)
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"

示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int isValid(string s) {
    stack<char> stk;
    stk.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!stk.empty() && stk.top() == '(' && s[i] == ')') {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

/**
 * 方法一：暴力穷举
 * 每次取2的整数倍子串，进行判断是否是符合的连续括号字符，不断更新最长的符合括号长度
 * 时间复杂度： O(n^3) 超时，无法通过
 */
int longestValidParentheses(string s) {
    if (s.size() <= 1) return 0;
    int max_count = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 2; j <= s.size(); j += 2) {
            if (isValid(s.substr(i, j - i))) {
                max_count = max(max_count, j - i);
            }
        }
    }
    return max_count;
}

/**
 * 方法二：括号问题，使用栈
 * 与找到每个可能的子字符串后再判断它的有效性不同，我们可以用栈在遍历给定字符串的
 * 过程中去判断到目前为止扫描的子字符串的有效性，同时能的都最长有效字符串的长度。
 * 我们首先将 -1−1 放入栈顶。
 * 对于遇到的每个 \text{‘(’}‘(’ ，我们将它的下标放入栈中。 对于遇到的每个')'
 * 我们弹出栈顶的元素并将当前元素的下标与弹出元素下标作差，得出当前有效括号字符串
 * 的长度。通过这种方法，我们继续计算有效子字符串的长度，并最终返回最长有效子字符串
 * 的长度。
 * Reference: https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
 */ 
int longestValidParenthesesII(string s) {
    int max_len = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                max_len = max(max_len, i - stk.top());
            }
        }
    }
    return max_len;
}

/**
 * 方法三：动态规划
 * 定义一个数组dp，dp[i]表示，从0到下标i位置的字符最长有效子字符串的长度。
 * 首先将dp数组全初始化为0。明确一下条件：
 *  （1）有效的子字符串一定一 ')' ，从而可知，
 * 以 '(' 结尾的子字符串对应的 dp 数组位置上的值必为0。所以我们只要更新 ')'
 * 对应的dp
 *
 * 为了求出dp数组，这里每两个字符检查一次，如果满足以下条件：
 *  （1）s[i] == ')' 且 s[i-1] == '('，形如：".....()"这样的
 *          dp[i] = dp[i-2] + 2
 * 即说明当前连续两个括号匹配，将有效子字符串长度增加2。(但要注意考虑边界i-2<0的处理)
 *  （2）s[i] == ')' 且 s[i-1] == ')'，形如：".....))"，我们可以推出：
 * 如果s[i-dp[i-1]-1] == '("，那么
 *          dp[i] = dp[i-1] + dp[i-dp[i-1]-2]+2
 * 如下：dp[7] = d[6] + dp[3] + 2，即描述的是dp[6]子串的最长长度 + (4-7)之前匹配
 * 的最长长度 dp[3] 加上 7这个位置匹配后会长度 + 2
 *
 *
 *    i  |   0   1   2   3   4   5   6   7
 *    c  |   (   )   )   (   (   (   )   )
 *    dp |   0   2   0   0   0   0   2   4
 */
int longestValidParenthesesIII(string s) {
    if (s.size() <= 1) return 0;
    int max_len = 0;
    vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')' && s[i - 1] == '(') {
            dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;   // 这里对于 i == 1 时的匹配，则dp[1] = 0 + 2
        } else if (i - dp[i - 1] - 1 >= 0 && s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0) + 2; // 对于小于0的dp，用0来处理
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

/**
 * 方法四：左扫一遍，右扫一遍 （没有细看，后面补充）
 */ 

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    cout << longestValidParenthesesII(s) << endl;
    cout << longestValidParenthesesIII(s) << endl;
    return 0;
}