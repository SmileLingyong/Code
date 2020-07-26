/**
 * Creation         :       2019.04.02 08:59
 * Last Reversion   :       2019.04.02 08:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Fibonacci(斐波拉契数列)
 * 题目描述
 *    大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）
 * n<=39
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    printf("Please input the int number: \n");
    scanf("%d", &n);
    return 0;
}