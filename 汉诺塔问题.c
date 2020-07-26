/**
 * Creation         :       2019.03.03 20:43
 * Last Reversion   :       2019.03.03 20:43
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 汉诺塔问题（TowersOfHanoi）
 * 汉诺塔的算法就3个步骤：
 *      第一，把a上的n-1个盘通过b移动到c。
 *      第二，把a上的最下面的盘移到b。
 *      第三，因为n-1个盘全在c上了，所以把c当做a重复以上步骤就好了。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>

int i = 1;
void Move(int i, int n, char a, char b) {
    printf("step %d : put %d from %c to %c\n", i, n, a, b);  // 将第 n个盘子由a移动到 b
}

void Hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        Move(i++, n, a, b);
    } else {
        Hanoi(n - 1, a, c, b);  // 将前n-1个盘子由a借助b移动到c
        Move(i++, n, a, b);     // 然后将 a剩余的第 n个盘子移动到 b
        Hanoi(n - 1, c, b, a);  // 再将 c上n-1个盘子借助a移动到b,即可
    }
}

int main() {
    int n;
    printf("Please input a int number:");    
    scanf("%d", &n);
    Hanoi(n, 'a', 'b', 'c');    // 将n个盘子由 a借助c,移动到 b
    return 0;
}