/**
 * Creation         :       2019.04.06 11:10
 * Last Reversion   :       2019.04.06 11:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    在如下一堆数字中选出一些数字，如何让数字之和最大？
 * 限定条件：选出的数字不能是相邻的。
 * arr[7] = {1, 2, 4, 1, 7, 8, 3}
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int arr[7] = {1, 2, 4, 1, 7, 8, 3};

/**
 * 递归形式，不好存在很多重叠子问题
 */ 
int RecOpt(int n) {
    if (n == 0)
        return arr[0];
    else if (n == 1)
        return max(arr[0], arr[1]);
    else
        return max(RecOpt(n - 2) + arr[n], RecOpt(n - 1));
}

/**
 * 非递归形式：动态规划
 */ 
int DPOpt(int n) {
    if (n == 0)
        return arr[0];
    else if (n == 1)
        return max(arr[0], arr[1]);
    
    int *OPT = (int*)malloc(sizeof(int) * (n + 1));     // 注意这里开辟的数组大小，n为下标，从0开始
    OPT[0] = arr[0];
    OPT[1] = max(arr[0], arr[1]);
    for (int i = 2; i <= n; i++) {
        OPT[i] = max(OPT[i-2] + arr[i], OPT[i-1]);
    }
    int res = OPT[n];
    free(OPT);
    return res;
}

int main() {
    int n;
    printf("Please input a int number (0~7):\n");
    while (~scanf("%d", &n) && n >= 0 && n <= 7) {
        printf("%d\n", DPOpt(n));
    }
    return 0;
}