/**
 * Creation         :       2019.03.08 19:40
 * Last Reversion   :       2019.03.08 19:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * ArrayFind(二维数组中的查找)
 * 题目描述
 *    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右
 * 递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 例如：
 *      1   2   8   9
 *      2   4   9   12
 *      4   7   10  13
 *      6   8   11  15
 * 如果查找数字 7，则返回true
 * 如果查找数字 5，则放回false
 * 
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100

/**
 * 方法一：直接遍历，找到返回True，遍历完没找到，返回False
 */
int ArrayFind(int target, int *p, int row, int col) {
    for (int i = 0; i < row * col; i++)
        if (*(p + i) == target) return 1;
    return 0;
}

int main() {
    int *p = NULL, row, col, target;
    printf("Please input the array row num: ");
    scanf("%d", &row);
    printf("Please input the array col num: ");
    scanf("%d", &col);
    p = (int *)malloc(sizeof(int) * row * col);

    printf("Please input the array: \n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) 
            scanf("%d", p + i * col + j);
    printf("Please input the target number: \n");
    scanf("%d", &target);

    if (ArrayFind(target, p, row, col))
        printf("true.\n");
    else
        printf("false.\n");

    free(p);
    return 0;
}