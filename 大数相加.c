/**
 * Creation         :       2019.03.07 10:44
 * Last Reversion   :       2019.03.07 11:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 大数相加
 *      思路1：模拟手工加法，先将两个数倒叙存储在两个数组中，比如：
 * s1 = "123";    n1 = {3, 2, 1};
 * s2 = '45678';  n2 = {8, 7, 6, 5, 4};
 * 然后就可以将 n1 和 n2，从低位开始相加，进位提前加入下一位。最后倒序输出即可。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <string.h>
#define MAXN 10000

void BigNumAdd(char s1[], char s2[], int n1[], int n2[], int sum[], int idx) {
    // 将两个大整数逆序，存放在新的数组中
    int len1, len2, len, i, j;
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (i = len1 - 1, j = 0; i >= 0; i--) n1[j++] = s1[i] - '0';
    for (i = len2 - 1, j = 0; i >= 0; i--) n2[j++] = s2[i] - '0';

    // 两个大整数相加，debug理解一下
    len = len1 > len2 ? len1 : len2;
    for (i = 0; i < len; i++) {
        sum[i] = sum[i] + n1[i] + n2[i];
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10;  // 保存进位
            sum[i] %= 10;               // 取余
        }
    }

    // 处理最高位的进位，如果最高位有进位，则len++，用于打印输出
    if (sum[len] > 0) len++;

    // 打印输出结果
    printf("Case %d: %s + %s = ", idx + 1, s1, s2);
    for (i = len - 1; i >= 0; i--) printf("%d", sum[i]);
    printf("\n\n");
}

int main() {
    int T;
    char s1[MAXN], s2[MAXN];
    int n1[MAXN], n2[MAXN];
    int sum[MAXN * 2];
    printf("Please input test case num: \n");
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        printf("Please input two big number: \n");
        scanf("%s %s", s1, s2);
        memset(n1, 0, sizeof(n1));  // 将数组元素都初始化为0
        memset(n2, 0, sizeof(n2));
        memset(sum, 0, sizeof(sum));
        BigNumAdd(s1, s2, n1, n2, sum, i);
    }
}