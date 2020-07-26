/**
 * Creation         :       2019.04.01 21:00
 * Last Reversion   :       2019.04.01 21:11
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * JumpFloor(青蛙跳台阶)
 * 题目描述
 *    一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>

/**
 * 思路：
 *    把n级台阶的跳法看成n的函数，记为f(n)。当 n>2 时，第一次跳的时候就有两种不同的选择:
 * 一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数目，即为f(n-1);
 * 二是第一次跳2级，此时跳法数目等于后面剩下的n-2级台阶的跳法数目，即为f(n-2)。
 * 因此，n级台阶的不同跳法的总数f(n)=f(n-1)+f(n-2)。分析到这里，我们不难看出这实际上就是斐波那契数列了。
 */ 
int JumpFloor(int number) {
    if (number == 1) return 1;
    if (number == 2) return 2;
    int a = 1, b = 2, c, i;
    for (i = 3; i <= number; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Please input the int number:\n");
    while (scanf("%d", &n)) 
        printf("The total floor is %d\n", JumpFloor(n));
    return 0;
}