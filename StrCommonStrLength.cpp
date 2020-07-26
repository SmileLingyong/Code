/**
 * Creation         :       2019.04.10 12:05
 * Last Reversion   :       2019.04.10 12:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * CommonStrLength(最长公共子串)
 * 题目描述b
 *    给定任意俩组字符串 S1 和 S2，请编程输出他们间的最大相同子串。例如：
 * S1=12abc78
 * S2=7bc2
 * 则输出为： bc (字符串数组)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    int i, j, sum, max, now, key, max_len;
    int len[100] = {0};
    cin >> a >> b;
    if (a.size() < b.size()) {
        swap(a, b);
    }
    for (i = 0; i < a.size(); i++) {
        now = i;
        max = 0;
        for (j = 0; j < b.size(); j++) {
            sum = 0;
            while (a[i] == b[j] && a[i] != '\0') {
                sum++;
                i++;
                j++;
                if (max < sum) {
                    max = sum;
                }
            }
            i = now;
        }
        len[now] = max;
    }

    max_len = 0;
    key = 0;
    for (i = 0; i < a.size(); i++) {
        if (max_len < len[i]) {
            max_len = len[i];
        }
    }
    for (i = 0; i < a.size(); i++) {
        if (len[i] == max_len) {
            key = i;
            for (int j = 0; j < max_len; j++) {
                cout << a[key++];
            }
            cout << " ";
        }
    }
    return 0;
}