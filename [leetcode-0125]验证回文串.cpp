/**
 * Creation         :       2019.08.22 00:32
 * Last Reversion   :       2019.08.22 00:32
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:t
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isRight(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        return true;
    return false;
}

bool isPalindrome(string s) {
    int length = s.size();
    for (int i = 0, j = length - 1; i <= j; ) {
        if (!isRight(s[i])) 
            i++;
        if (!isRight(s[j]))
            j--;
        if (isRight(s[i]) && isRight(s[j])) {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;
    return 0;
}