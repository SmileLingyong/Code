/**
 * Creation         :       2019.04.08 14:26
 * Last Reversion   :       2019.04.08 14:
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * Print1ToMaxOfNDigits(打印从 1 到最大的 n 位数)
 * 题目描述
 *    输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，
 * 则打印出 1、2、3 一直到最大的 3 位数即 999。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 方法一：大数相加
 */ 

/**
 * 方法二：全排列 (这题和华为的那道笔试题很像，基本就是一样的)
思路：n位所有十进制数，其实就是n个从0到9的全排列。即，我们可以通过把数字的每一位都从0到9排列一遍，就
得到了所有的十进制数。只是在打印的时候，排在前面的0不打印罢了。
 */ 
void PrintNumber(char *number) {
    int isBegining0 = 1;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; i++) {
        if (isBegining0 && number[i] != '0') 
            isBegining0 = 0;
        if (!isBegining0)               // 碰到第一个非0字符才开始打印，因为0036前面的0不应该打印
            printf("%c", number[i]);
    }
    printf("\n");
}

void Print1ToMaxOfNdigitsRecursively(char *number, int length, int index) {
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNdigitsRecursively(number, length, index + 1);
    }
}


void Print1ToMaxOfNdigits(int n) {
    if (n <= 0)
        return;
    char *number = (char*)malloc(sizeof(char) * (n + 1));
    number[n] = '\0';

    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        Print1ToMaxOfNdigitsRecursively(number, n, 0);
    }
    free(number);
}


#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    Print1ToMaxOfNdigits(n);
    return 0;
}