/**
 * Creation         :       2019.06.30 20:28
 * Last Reversion   :       2019.06.30 20:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * longestCommonPrefix(最长公共前缀) 
 * 题目描述
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:
所有输入只包含小写字母 a-z 。
 * -----------------------------------------------------------------
 * Reference： https://leetcode-cn.com/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode/
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 获取两个字符串的最长公共前缀
 */ 
string CommonPrefix(string &A, string &B) {
    string res = "";
    int size = min(A.size(), B.size());
    for (int i = 0; i < size; i++) {
        if (A[i] == B[i])
            res += A[i];
        else 
            break;
    }
    return res;
}

/**
 * 方法一：水平扫描法，先两个找最长公共前缀，再用该前缀与后面一个字符串找前缀，
 * 直到没有公共前缀，或遍历到末尾，返回最长公共前缀
 * 时间复杂度： O(S)
 * 空间复杂度： O(1)
 * （想象数组的末尾有一个非常短的字符串，使用上述方法依旧会进行 ​S​ 次比较。）
 */ 
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string com_str = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        com_str = CommonPrefix(com_str, strs[i]);
        if (com_str.empty()) {
            return "";
        }
    }
    return com_str;
}

/**
 * 方法二：水平扫描，相当于将所有字符一行行排好，然后按列开始扫描
 * 时间复杂度：O(S)
 * 空间复杂度：O(1)，我们只需要使用常数级别的额外空间
 */ 
string longestCommonPrefixII(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];
    for (int i = 0; i < strs[0].size(); i++) {
        char start = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i == strs[j].size() || strs[j][i] != start) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

/**
 * 方法三：分治思想
 * 时间复杂度：O(S)，S 是所有字符串中字符数量的总和，S=m∗n
 * 空间复杂度：O(m*log(n))
 * 内存开支主要是递归过程中使用的栈空间所消耗的。一共会进行 log(n) 次递归，每次需要 m 的空间存储返回结果
 */ 
string longestCommonPrefix(vector<string> &strs, int l, int r) {
    if (l == r)
        return strs[l];
    else {
        int mid = (l + r) / 2;
        string lcp_left = longestCommonPrefix(strs, l, mid);
        string lcp_right = longestCommonPrefix(strs, mid + 1, r);
        return CommonPrefix(lcp_left, lcp_right);
    }
}

string longestCommonPrefixIII(vector<string>& strs) {
    if (strs.empty()) return "";
    return longestCommonPrefix(strs, 0, strs.size()-1);
}

/**
 * 方法四：二分查找法（这个后面要完善）
 */ 
string longestCommonPrefixIV(vector<string>& strs) {
    
}

int main() {
    int n;
    string str;
    vector<string> strs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strs.push_back(str);
    }
    cout << longestCommonPrefix(strs) << endl;
    cout << longestCommonPrefixII(strs) << endl;
    cout << longestCommonPrefixIII(strs) << endl;
    return 0;
}