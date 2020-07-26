/**
 * Creation         :       2019.04.22 13:59
 * Last Reversion   :       2019.04.22 14:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
NumDecodings(解码方法) leetcode-91
题目描述
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2:
输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */ 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 方法一：动态规划，其实就是约束版的 f(n) = f(n-1) + f(n-2)
 * 实际上有两个约束条件：
 *  (1) 0不能单独解码
 *  (2) 两位数必须在1到26之间
 * 
 * 定义状态：
 * dp[i]：表示s从0开始，长度为 i 的子串的解码方式数量，所以最终答案为 dp[n]
 * 如何求解 dp[i]？通过枚举最后一个字母对应1位还是2位，将dp[i]转换为规模更小的子问题
 *  (1) 初始化 dp[i] 全为0
 *  (2) 枚举最后一个字母对应1位 （要求s[i-1] != '0',即前一位不能为0，因为0无法单独解码），那么有 dp[i] += dp[i-1]
 *  (3) 枚举最后一个字母对应2位（要求 i > 1 且 s[i-2] 和 s[i-1] 组成的字符串在 ”10“到”26“的范围内）
 * 那么有 dp[i] += f[i-2]
 */ 
int numDecodings(string s) {
    if (s.size() == 0 || (s.size() == 1 && s[0] == '0'))
        return 0;
    if (s.size() == 1)
        return 1;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    // 从1～n依次计算dp[i]
    for (int i = 1; i <= s.size(); i++) {
        // 选当前一位解码
        if (s[i - 1] > '0') 
            dp[i] += dp[i - 1];
        // 能够选当前位+上一位，共两位解码
        if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))  // 等价于if (i > 1 && s.substr(i-2, 2) >= "10" && s.substr(i-2, 2) <= "26")
            dp[i] += dp[i - 2];
    }
    return dp[s.size()];
}


int main() {
    string str;
    cin >> str;
    cout << numDecodings(str) << endl;;
    return 0;
}
