/**
 * Creation         :       2019.03.07 14:51
 * Last Reversion   :       2019.03.07
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 大数相乘
 *      思路1：模拟手工乘法，先将两个数倒序存储在两个数组中，比如：
 * s1 = "999";   n1 = {9, 9, 9};
 * s2 = '99';    n2 = {9, 9};
 *        9    9    9 
 *  x          9    9
 * ---------------------
 *        (81)(81)(81)  <---- 第1趟: 999×9的每一1位结果 
 *    (81)(81)(81)      <---- 第2趟: 999×9的每一位结果 
 * ---------------------
 *  (81)(162)(162)(81)  <---- 这里就是相对位的和，还没有累加进位
 * 然后进行进位处理即可.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>
#define N 1000

void BigNumMul(char s1[], char s2[], int n1[], int n2[], int mul[], int idx) {
    int len1, len2, len, i, j, pre;
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (i = len1 - 1, j = 0; i >= 0; i--) n1[j++] = s1[i] - '0';
    for (i = len2 - 1, j = 0; i >= 0; i--) n2[j++] = s2[i] - '0';

    len = len1 + len2;

    // 手工乘法，进位先不处理
    for (i = 0; i < len1; i++)
        for (j = 0; j < len2; j++) 
            mul[i + j] += n1[i] * n2[j];
    // 处理进位
    for (i = 0; i < len; i++) {
        pre = mul[i] / 10;
        mul[i+1] += pre;
        mul[i] %= 10;
    }
    // 处理最高位的进位
    if (mul[len] > 9) 
        len++;
    // 打印输出
    printf("Case %d: %s * %s = ", i, s1, s2);        
    for(i = len-1; i >= 0; i--)
        printf("%d", mul[i]);
    printf("\n");
}

int main() {
    int T;
    char s1[N], s2[N];
    int n1[N], n2[N], mul[N * N];
    printf("Please input the num of cese: \n");
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        printf("Please input two number: \n");
        scanf("%s %s", &s1, &s2);
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));
        memset(mul, 0, sizeof(mul));
        BigNumMul(s1, s2, n1, n2, mul, i);
    }
    return 0;
}
