/**
 * Creation         :       2019.04.09 11:03
 * Last Reversion   :       2019.04.09 11:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 正整数分解(PosIntDecomposite)
 * 问题描述：
 *    将一个正整数分解质因数。例如：输入 90,打印出 90=2*3*3*5。
 * 思路：
 *    对 n 进行分解质因数，应先找到一个最小的质数 k，然后按下述步骤完成：
 * (1)如果这个质数恰等于 n，则说明分解质因数的过程已经结束，打印出即可。
 * (2)如果 n > k，但 n 能被 k 整除，则应打印出 k 的值，并用 n 除以 k 的商,
 *    作为新的正整数 n, 重复执行第一步。
 * (3)如果 n 不能被 k 整除，则用 k+1 作为 k 的值,重复执行第一步。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
int main() {
    int n, i;
    printf("Please input a int number:");
    scanf("%d", &n);
    printf("%d = ", n);
    if (n == 1)
        printf("1");
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n != 1)
                printf(" * ");
        }
    }
    printf("\n");
    return 0;
}