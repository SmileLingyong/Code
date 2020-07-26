/**
 * Creation         :       2019.03.08 16:26
 * Last Reversion   :       2019.03.08 16:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Duplicate(数组中重复的数字)
 * 题目描述
 *    在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
 * 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 * 思路： 
 *    （方法一）：两重循环，每次将第i个，与后面的进行比较，直到找到重复的，或遍历完成。时间复杂度 O(n^2)
 *    （方法二）：因为是从0到n-1，如果不重复，那么每个下标和其数应该相等，如果不等，
 * 我们就将当前数，交换到其应该在的下标位置。如果，此时要交换的两个数相等，则说明有重复数字。
 * 否则遍历完整个序列都不会有重复数字。自己举个例子打一遍即可： [0 1 2 4 3 3] 和 [0 1 2 5 3 4]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#define N 1000

/**
 * @brief Duplicate:        Function
 * @param int numbers[]:    An array of integers
 * @param int length:       The length of array numbers
 * @param int *duplication: (Output) the duplicated number in the array number
 * @return bool:            True if the input is valid, and there are some duplications in the array number, 
 *                          Otherwise false
 */
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

/* 书中的解法3 */
bool Duplicate(int numbers[], int length, int *duplication) {
    int i, temp;
    for (i = 0; i < length; i++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            temp = numbers[i];
            numbers[i] = numbers[numbers[i]];
            numbers[temp] = temp;
        }
    }
    return false;
}


int main() {
    int a[N], n, i, duplication;
    printf("Please the array length: \n");
    scanf("%d", &n);
    printf("Please input the array: \n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    // if (DuplicateLLY(a, n, &duplication))   
    if (Duplicate(a, n, &duplication))   
        printf("There is a duplication: %d\n", duplication);
    else
        printf("There isn't a duplication!\n");
    return 0;
}
