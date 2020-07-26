/**
 * Creation         :       2019.03.08 19:32
 * Last Reversion   :       2019.03.08 
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DuplicateOne(不修改数组找出重复的数字)
 * 题目描述
 *    在一个长度为n+1的数组里的所有数字都在0到1～n的范围内，所以数组中至少
 * 有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 1000

bool DuplicateLLY(int numbers[], int length, int *duplication) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (numbers[i] == numbers[j]) {
                *duplication = numbers[i];
                return true;
            }
        }
    }
    return false;
}

bool Duplicate(int numbers[], int length, int *duplication) {
    return false;
}

int main() {
    int a[N], n, i, duplication;
    printf("Please the array length: \n");
    scanf("%d", &n);
    printf("Please input the array: \n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    // if (DuplicateLLY(a, n, &duplication))   
    if (DuplicateLLY(a, n, &duplication))   
        printf("There is a duplication: %d\n", duplication);
    else
        printf("There isn't a duplication!\n");
    return 0;
}