/**
 * Creation         :       2019.04.10 11:45
 * Last Reversion   :       2019.04.10 12:05
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * StrLongestNumberStr(求字符串中连续出现最长的数字串)
 * 题目描述
 *    设计一个程序，输入一个字符串，则输出此字符串中连续出现最长的数字
 * 串及其开始的下标。
 * 例如：
 *    输入： ab125ef1234567
 *    输出： 1234567 开始位置为： 8
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int i, j, sum = 0, max, now, key, max_len, first_time = 1;
    int len[100] = {0};
    cin >> a;
    for (i = 0; i < a.size(); i++) {
        now = i;
        sum = 0;
        while (a[i] >= '0' && a[i] <= '9' && a[i] != '\0') {
            sum++;
            i++;
        }
        i = now;
        len[i] = sum;
    }
    
    max_len = 0;
    for (i = 0; i < a.size(); i++) {
        if (max_len < len[i]) {
            max_len = len[i];
        }
    }
    key = 0;
    for (i = 0; i < a.size(); i++) {
        if (len[i] == max_len) {
            key = i;
            // 输出中间的空格
            if (first_time) {
                first_time = 0;
            } else {
                cout << " ";
            }
            for (int j = 0; j < max_len; j++) {
                cout << a[key++];
            }
        }
    }
    return 0;
}