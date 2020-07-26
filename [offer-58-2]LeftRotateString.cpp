/**
 * Creation         :       2019.07.19 00:41
 * Last Reversion   :       2019.07.19 11:04
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
LeftRotateString (左旋转字符串)
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟
这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，
字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简
单？OK，搞定它！
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 方法一：先将需要前 n 位翻转，然后再将后面的翻转，最后将整体翻转即可。
 */ 
string LeftRotateString(string str, int n) {
    int length = str.size();
    if (length == 0) return "";
    if (n > length) 
        n %= length;
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    string str = "abcXYZdef";
    int n = 0;
    cout << LeftRotateString(str, n) << endl;
    return 0;
}