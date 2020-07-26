/**
 * Creation         :       2019.05.08 16:24
 * Last Reversion   :       2019.05.08 16:24
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * LongestPalindrome(最长回文子串)
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
 * -----------------------------------------------------------------
 * Reference: 
 *  - http://www.cnblogs.com/grandyang/p/4464476.html
 *  - https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 是否是回文
 */ 
bool isPalindrome(const string str) {
    for (int i = 0, j = str.length()-1; i <= j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}

/**
 * 方法一：暴力法
 *    从长度为str.length()的子串开始找，判断其是否为回文字符串O(n)，如果不是，长度-1，再找
 * 时间复杂度： O(n^3)   [超时了！]
 */ 
string longestPalindrome(string s) {
    string res = "";
    for (int cur_len = s.length(); cur_len >= 0; cur_len--) {
        for (int i = 0; (i < s.length()) && (i + cur_len <= s.length()); i++) {
            res = s.substr(i, cur_len);
            if (isPalindrome(res))
                return res;
        }
    }
    return res;
}

/**
 * 方法二：中心扩展算法
 * i从0开始，然后以两种方式进行两边扩展，因为有奇数和偶数的区别：
 * （1）奇数情况：比如 aba，则需要遍历到i==1的时候，以这一个点进行中心扩展
 * （2）偶数情况：比如 abba，则需要遍历到i==1的时候，以s[i]和s[i+1]这两个点进行中心扩展，判断回文长度
 * 最终，返回最终计算的最长回文子串
 */ 
void searchPalindrome(string s, int left, int right, int &start, int &max_len) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    if (max_len < right - left - 1) {
        start = left + 1;           // 更新最长回文子串的起始位置
        max_len = right - left - 1;
    }
}

string longestPalindromeII(string s) {
    if (s.size() < 2) return s;
    int n = s.size();
    int max_len = 0;    // 记录最长的回文子串长度
    int start = 0;      // 记录最长回文子串的起始位置
    for (int i = 0; i < n - 1; i++) {
        searchPalindrome(s, i, i, start, max_len);
        searchPalindrome(s, i, i+1, start, max_len);
    }
    return s.substr(start, max_len);
}

/**
 * 方法三：动态规划
 * (1)定义状态：二维数组dp，其中dp[l][r]表示字符串区间[l, r]是否为回文串，l，r分别是区间左右边界的索引
 * (2)找到”状态转移方程“
 * 
 * 首先我们要明确：
 * 1、当子串只包含 11 个字符，它一定是回文子串；
 * 2、当子串包含 2 个以上字符的时候：如果 s[l, r] 是一个回文串，例如 “abccba”，那么这个回文串两边各往里
 * 面收缩一个字符（如果可以的话）的子串 s[l + 1, r - 1] 也一定是回文串，即：如果 dp[l][r] == true 成
 * 立，一定有 dp[l + 1][r - 1] = true 成立。
 * 根据这一点，我们可以知道，给出一个子串 s[l, r] ，如果 s[i] != s[j]，那么这个子串就一定不是回文串。
 * 如果 s[i] == s[j] 成立，就接着判断 s[l + 1] 与 s[r - 1]，这很像中心扩散法的逆方法。
 * 即当 s[i] == s[j] 时，dp[l][r] 的值由 dp[l + 1][r - l] 决定。
 * 
 * 然后我们需要考虑：“原字符串去掉左右边界”的子串的边界情况：
 * 1、当原字符串的元素个数为 3 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 1 个字符，
 * 它一定是回文串，故原字符串也一定是回文串；
 * 2、当原字符串的元素个数为 2 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 0 个字符，
 * 显然原字符串也一定是回文串。
 * 
 * 把上面两点归纳一下，只要 s[l + 1, r - 1] 至少包含两个元素，就有必要继续做判断，否则直接
 * 根据左右边界是否相等就能得到原字符串的回文性。而“s[l + 1, r - 1] 至少包含两个元素”等价于
 * l + 1 < r - 1，整理得 l - r < -2，或者 r - l > 2
 * 
 * 综上：如果一个字符串左右边界相等，以下二乘之一成立即可。
 * 1、去掉左右边界以后的字符串不构成区间，即 l - r >= -2，或者 r - l <= 2
 * 2、去掉左右边界以后的字符串是回文串，具体说，它的回文性决定了原字符串的回文性。
 * 
 * 整理得到状态转移方程：
 * dp[l][r] = (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1]))
 * 
 * 编码实现细节：因为要构成子串，l 一定小于等于 r
 */ 
string longestPalindromeIII(string s) {
    if (s.size() < 2) return s;
    int dp[s.size()][s.size()] = {0};
    int left = 0, right = 0, max_len = 1;
    for (int r = 1; r < s.size(); r++) {
        for (int l = 0; l < r; l++) {
            if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                dp[l][r] = 1;
                if (max_len < r - l + 1) {
                    max_len = r - l + 1;    // 更新最长回文子串长度，并更新回文起始结束位置
                    left = l;
                    right = r;
                }
            }
        }
    }
    return s.substr(left, max_len);
}

/**
 * 方法四：Manacher 算法 （后面要完善）
 */ 

int main() {
    string str;
    cin >> str;
    cout << longestPalindromeIII(str);
    return 0;
}