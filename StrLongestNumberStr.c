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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char a[100];
    int now, sum, max_len, key, len_a = 0;
    int len[100] = {0};                 // 数组len记录每个位置是连续数字的最大长度
    scanf("%s", &a);
    len_a = strlen(a);
    for (int i = 0; i < len_a; i++) {
        sum = 0;
        now = i;
        while (a[i] >= '0' && a[i] <= '9') {
            sum++;
            i++;
        }
        i = now;
        len[i] = sum;
    }

    max_len = 0;
    for (int i = 0; i < len_a; i++) {
        if (max_len < len[i])
            max_len = len[i];           // 记录连续数字的最大长度
    }
    for (int i = 0; i < len_a; i++) {
        if (len[i] == max_len) {
            key = i;
            for (int j = 0; j < max_len; j++) {
                printf("%c", a[key++]);
            }
            printf("\n开始位置为：%d", key);
            printf("\n最大长度为：%d\n", max_len);
        }
    }
    return 0;
}