/**
 * Creation         :       2019.04.01 21:12
 * Last Reversion   :       2019.04.01 21:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * JumpFloorII(变态跳台阶)
 * 题目描述
 *    一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级... 它也可以跳上 n 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/**
 * 方法一：数学归纳出公式
 *    用数学归纳法可知：f(n) = 2^{n-1}
 * 可以直接使用快速幂来计算。
 */ 
int JumpFloorII(int number) {
    number--;
    int ans = 1;
    int base = 2;
    while (number) {
        if (number & 1) 
            ans *= base;
        base *= base;
        number /= 2;
    }
    return ans;
}

/**
 * 方法二：动态规划
 * （没看懂，后面要多看几遍！）
 */ 
int JumpFloorIIDP(int number) {
    int *dp = new int[number];
    for (int i = 0; i < number; i++) 
        dp[i] = 1;
    for (int i = 1; i < number; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j];
        }
    }
    return dp[number - 1];    
}

int main() {
    int n;
    printf("Please input the int number:\n");
    while (scanf("%d", &n)) {
        printf("The total floor is %d\n", JumpFloorII(n));
        printf("The total floor is %d\n", JumpFloorIIDP(n));
    }
    return 0;
}