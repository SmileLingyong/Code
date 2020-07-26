/**
 * Creation         :       2019.03.31 15:06
 * Last Reversion   :       2019.03.31 16:55
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 *
 * 题目描述：
 *    写一个整数计算器，支持加减乘除三种运算和括号
    输入：
      1+2
    输出：
      3

    输入：
      3+2*3*4-1
    输出：
      26
 * -----------------------------------------------------------------
 * Reference: 
 *   - https://blog.csdn.net/yaoxunji/article/details/79676744
 *   - https://blog.csdn.net/sgbfblog/article/details/8001651
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;

/**
 * 字符串预处理
 * 主要处理类似 -2+3, 1+(-3+2) 这类负数问题
 * 将其变为 (0-2+3), 1+(0-3+2)
 */ 
string Format(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-') {
            if (i == 0) {
                str.insert(0, 1, '0');
            } else if (str[i - 1] == '(') {
                str.insert(i, 1, '0');
            }
        }
    }
    return str;
}

/**
 * 确定操作符的优先级
 */ 
int Prior(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

/**
 * 中缀表达式转后缀表达式
 * 具体过程：
 *    1）如果遇到操作数，我们就直接将其输出。
 *    2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
 *    3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
 *    4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。
 *       弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
 *    5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
 */ 
vector<string> LNRToLRN(string str) {
    vector<string> output;
    stack<char> opt;
    for (int i = 0; i < str.length(); i++) {    // 遍历整个中缀表达式
        string tmp = "";    // 用于将char转换为字符串
        switch (str[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                if (opt.empty() || opt.top() == '(') {    // 栈为空，或者栈顶为左括号"("时，直接将当前数或'+-×/'压入栈中
                    opt.push(str[i]);
                } else {    // 栈不为空，并且栈顶操作符优先级 >= 当前操作符优先级时，则将栈顶操作符出栈并输出，再和下一个栈顶元素相比较，直到遇到发现更低优先级的栈顶元素(或者栈为空)为止。弹完这些元素后，才将遇到的操作符压入到栈中。
                            // 有一点需要注意，只有在遇到")"的情况下我们才弹出"("，其他情况我们都不会弹出"("
                    while (!opt.empty() && Prior(opt.top()) >= Prior(str[i])) {  
                        tmp += opt.top();
                        output.push_back(tmp);
                        opt.pop();
                        tmp = "";
                    }
                    opt.push(str[i]);
                }
                break;
            case '(':       // 遇到左括号"("，直接进栈
                opt.push(str[i]);
                break;
            case ')':       // 遇到右括号")"，则将栈中元素依次弹出，直到遇到"("为止。将弹出的元素输出(这里输出至vs中)，注意： "("只弹出，不输出
                while (opt.top() != '(') {
                    tmp += opt.top();
                    output.push_back(tmp);
                    opt.pop();
                    tmp = "";
                }
                opt.pop();  // 左括号"("出队
                break;
            default:
                if (str[i] >= '0' && str[i] <= '9') {     // 如果遇到操作数，直接将其输出（这里是存入vs）
                    tmp += str[i];  // 字符串拼接
                    while (i + 1 < str.size() && str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '.') {
                        tmp += str[i + 1];  // 若是连续数字
                        ++i;
                    }
                    output.push_back(tmp);
                }
        }
    }
    while (!opt.empty()) {      // 当遍历完后，栈不为空的话，则依次出栈
        string tmp = "";
        tmp += opt.top();
        output.push_back(tmp);
        opt.pop();
    }
    return output;
}

/**
 * 计算后缀表达式
 * 具体思路：
 *    遍历表达式，遇到的数字首先放入栈中；读到操作符op，则弹出两个数字A,B，执行AopB，将结压出栈中。
 * 后序操作以此类推，直到栈空为止。
 */ 
double Result(vector<string> output) {
    stack<double> opt;
    double num, A, B;
    for (int i = 0; i < output.size(); i++) {
        string tmp = output[i];
        if (tmp[0] >= '0' && tmp[0] <= '9') {
            num = atof(tmp.c_str());    // c_str()将string得到C类型的字符数组，返回的是char*,即字符数组的首地址。函数原型 const char*c_str() const;
            opt.push(num);
        } else if (output[i] == "+") {
            A = opt.top();
            opt.pop();
            B = opt.top();
            opt.pop();
            opt.push(A + B);
        } else if (output[i] == "-") {
            A = opt.top();
            opt.pop();
            B = opt.top();
            opt.pop();
            opt.push(A - B);
        } else if (output[i] == "*") {
            A = opt.top();
            opt.pop();
            B = opt.top();
            opt.pop();
            opt.push(A * B);
        } else if (output[i] == "/") {
            A = opt.top();
            opt.pop();
            B = opt.top();
            opt.pop();
            opt.push(A / B);
        }
    }
    return opt.top();
}

/**
 * 格式化输出
 */ 
void Solve(string str) {
    str = Format(str);
    vector<string> output = LNRToLRN(str);  // 将中序表达式转换为后序表达式
    double res = Result(output);            // 将后续表达式，计算结果
    if ((int)res == res) {                  // 整数输出
        printf("%d\n", (int)res);
    } else {
        printf("%.4f\n", res);              // 小数输出
    }
}

int main() {
    string str;
    while(getline(cin, str)) {
        Solve(str);
    }
}
