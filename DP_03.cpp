/**
 * Creation         :       2019.04.06 11:30
 * Last Reversion   :       2019.04.06 15:39:
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    在如下一堆数字中选出一些数字求和，能够等于数字n。如果存在这样的方案则
 * 返回true，否则返回false。
 * int arr[] = {3, 34, 4, 12, 5, 2};
 * 测试用例：
 输入：
9
10
11
12
13
 输出：
1
1
1
1
0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_SIZE 100
#define M_SIZE 100

int arr[] = {3, 34, 4, 12, 5, 2};
int subset[N_SIZE][M_SIZE];

/**
 * 递归形式
 */ 
int RecSubset(int arr[], int i, int S) {
    if (i == 0)                 // 这里的两个出口和调换了一下顺序（与笔记想笔记），因为比如当数组只有一个元素arr[] = {4}, S = 5，此时因该返回False才对。
        return (arr[0] == S);
    else if(S == 0)
        return 1;
    else 
        return RecSubset(arr, i-1, S-arr[i]) || RecSubset(arr, i-1, S);
}

/**
 * 非递归形式：动态规划
 */ 
int DPSubset(int arr[], int len, int S) {
    for (int i = 0; i < len; i++) {     // 将S == 0 列都初始化为True
        subset[i][0] = 1;
    }
    for (int s = 0; s <= S; s++) {      // 将 i == 0 行，除了arr[0]列初始化为True，其余都初始化为False，即多补了一列
        subset[0][s] = 0;
    }
    subset[0][arr[0]] = 1;

    for (int i = 1; i < len; i++) {
        for (int s = 1; s <= S; s++) {
            if (arr[i] > s)
                subset[i][s] = subset[i-1][s];
            else {
                subset[i][s] = (subset[i-1][s-arr[i]] || subset[i-1][s]);
            }
        }
    }
    return subset[len-1][S];
}

int main() {
    if (RecSubset(arr, 5, 13))
        printf("True\n");
    else
        printf("False\n");
    if (DPSubset(arr, 6, 13))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}