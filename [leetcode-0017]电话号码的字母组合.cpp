/**
 * Creation         :       2019.06.21 15:41
 * Last Reversion   :       2019.06.21 15:41
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * letterCombinations(电话号码的字母组合)
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

思路：
   我们用递归 Recursion 来解，我们需要建立一个字典，用来保存每个数字所代表的字符串，
然后我们还需要一个变量 index，记录当前生成的字符串的字符个数，实现套路和上述那些
题十分类似。在递归函数中我们首先判断 index，如果跟 digits 中数字的个数相等了，
我们将当前的组合加入结果 res 中，然后返回。否则我们通过 digits 中的数字到 dict
中取出字符串，然后遍历这个取出的字符串，将每个字符都加到当前的组合后面，并调用递归
函数即可
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void letterCombinationsDFS(string &digist, vector<string> &dict, int index, string out, vector<string> &res) {
    if (index == digist.size()) {
        res.push_back(out);
        return;
    }
    string str = dict[digist[index] - '0'];
    for (int i = 0; i < str.size(); i++) {
        letterCombinationsDFS(digist, dict, index + 1, out + str[i], res);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> res;
    vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, "", res);
    return res;
}

int main() {
    string digits;
    cin >> digits;
    vector<string> res = letterCombinations(digits);
    for (vector<string>::iterator iter = res.begin(); iter != res.end();
         iter++) {
        cout << *iter << endl;
    }
    return 0;
}