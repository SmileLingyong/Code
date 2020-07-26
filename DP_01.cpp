/**
 * Creation         :       2019.04.05 14:50
 * Last Reversion   :       2019.03.05 15:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    最多能赚几块钱(动态规划) 结合笔记题目查看，其实和斐波拉契数列是差不多的。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int v[9] = {0, 5, 1, 8, 4, 6, 3, 2, 4};     // 注意这里前面多补了一个0，是为了方便和笔记对应
int prev[9] = {0, 0, 0, 0, 1, 0, 2, 3, 5};  // 这里的prev数组是自己预先算好了的

/**
 * 递归形式：存在重叠子问题
 */ 
int RecOpt(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 5;
    return max(RecOpt(n - 1) , v[n] + RecOpt(prev[n]));
}

/**
 * 非递归形式：（动态规划）
 */ 
int DPOpt(int n) {
    if (n == 0)                                         // 出口
        return 0;   
    if (n == 1)                                         // 出口
        return 5;
    int *OPT = (int*)malloc(sizeof(int) * (n + 1));     // 这里多开辟了一个int空间大小，是为了和公式下标对应
    OPT[0] = 0;     
    OPT[1] = 5;
    for (int i = 2; i <= n; i++) {
        OPT[i] = max(OPT[i-1], v[i] + OPT[prev[i]]);
    }
    int res = OPT[n];
    free(OPT);
    return res;
}


int main() {
    int n;
    printf("Please input a int number (1~8):\n");
    while (~scanf("%d", &n) && n >= 1 && n <= 8) {
        printf("%d\n", DPOpt(n));
    }
    return 0;
}