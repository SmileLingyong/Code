/**
 * Creation         :       2019.05.08 14:15
 * Last Reversion   :       2019.05.08 14:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
GenerateParenthesis(括号生成)
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 回溯方法：八皇后、国际象棋、马跳日等都是类似的
 *    思路： 字符串只有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括
 * 号3个，所以我们定义两个变量left和right分别表示剩余左右括号的个数，如果在某次递
 * 归时，左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号
 * 的个数，即会出现')('这样的非法串，所以这种情况直接返回，不继续处理。如果left和
 * right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存
 * 入结果中后返回。如果以上两种情况都不满足，若此时left大于0，则调用递归函数，注意
 * 参数的更新，若right大于0，则调用递归函数，同样要更新参数。
 */ 
void addingPar(int left, int right, string out, vector<string> &res) {
    if (left > right) return;
    if (left == 0 && right == 0)
        res.push_back(out);
    else {
        if (left > 0) addingPar(left - 1, right, out + '(', res);
        if (right > 0) addingPar(left, right - 1, out + ')', res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingPar(n, n, "", res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> res;
    res = generateParenthesis(n);
    for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}