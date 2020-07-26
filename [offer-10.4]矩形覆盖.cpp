/**
 * Creation         :       2019.04.01 21:39
 * Last Reversion   :       2019.04.01 22:01
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * RectCover(矩形覆盖)
 * 题目描述
 *    我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>

/**
 * 思路：依旧是斐波拉契数列思想
 */ 
int RectCover(int number) {
    if (number <= 2) 
        return number;
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
        printf("The total floor is %d\n", RectCover(n));
    return 0;
}
