/**
 * Creation         :       2019.05.08 09:53
 * Last Reversion   :       2019.05.08 09:53
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
IsValid(有效的括号)
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isMatch(char left, char right) {
    if (    (left == '[' && right == ']')
        ||  (left == '(' && right == ')')
        ||  (left == '{' && right == '}')   )
        return true;
    else
        return false;
}

bool isValid(string s) {
    if (s.empty())      // 注意这里不要用.size() 而要用 .empty()
        return true;
    stack<char> stk; 
    stk.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!stk.empty() && isMatch(stk.top(), s[i]))
            stk.pop();
        else 
            stk.push(s[i]);
    }
    return stk.empty();
}

int main() {
    string str;
    cin >> str;
    if (isValid(str)) 
        cout << "true";
    else
        cout << "false";
    return 0;
}