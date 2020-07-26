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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char a[100], b[100];    // 存放字符串数组
    int i, j, sum, max, max_len, now, key, len_a, len_b;
    int len[100] = {0};     // 存放 每个字符 a[i]与 b 串所匹配的最长子串长度
    scanf("%s %s", &a, &b);
    if (strlen(a) < strlen(b)) {
        char temp[100];
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    len_a = strlen(a);
    len_b = strlen(b);
    
    for (i = 0; i < len_a; i++) {
        now = i;                    // 保存当前用于匹配的a[i]
        max = 0;                    // 保存与a[i]匹配的最大长度
        for (j = 0; j < len_b; j++) {
            sum = 0;                // 每当不匹配了，就将sum清零
            while (a[i] == b[i] && a[i] != '\0') {  // 若匹配成功，a b 均后移继续匹配
                i++;
                j++;
                sum++;
                if (max < sum) {
                    max = sum;
                }
            }
            i = now;                // 断了，又重a[i]开始匹配
        }
        len[now] = max;
    }

    max_len = 0;
    key = 0;
    for (i = 0; i < len_a; i++) {   // 最大匹配长度          
        if (max_len < len[i]) {
            max_len = len[i];
        }
    }

    for (i = 0; i < len_a; i++) {   // 若有多个一样长的最大相同子串，则都打印
        if (len[i] == max_len) {
            key = i;
            for (int j = 0; j < max_len; j++) {
                printf("%c", a[key++]);
            }
            printf(" ");
        }
    }
    return 0;
}