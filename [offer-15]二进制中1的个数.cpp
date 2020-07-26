/**
 * Creation         :       2019.04.08 11:00
 * Last Reversion   :       2019.04.08 11:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * NumberOf1(二进制中1的个数)
 * 题目描述
 *    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

/**
 * 方法三：巧妙思想
 *    把一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0。那么一个
 * 整数的二进制表示中有多少个1，就可以进行多少次这样的操作。
 *    例如： 1100, 减去1后，为1011，然后将1100与1011做与运算，得到1000。即把该
 * 整数最右边的1变成了0。
 */ 
int NumberOf1Nice(int n) {
    int count = 0;
    while (n) {
        ++count;
        n = n & (n - 1);    // 这个非常常用，一定要会！
    }
    return count;
}   

/**
 * 方法二：常规解法
 *    为了避免死循环，我们不移动n，而是先把n与1与运算，判断n的最低位是不是1。然后把
 * flag=1左移一位得到flag=2，再用flag与n与操作，即可判断n的倒数第二位是不是1。
 * 以此类推。（这个解法中，循环的次数等于整数二进制的位数，32位的整数需要循环32次）
 */ 
int NumberOf1(int n) {
    int count = 0;
    unsigned int flag = 1;  // 注意这里要定义成无符号整形
    while (flag) {
        if (n & flag)
            count++;
        flag <<= 1;         // flag 左移一位
    }
    return count;
}

/**
 * 方法一：直接与1按位与，右移操作。
 *    先判断整数二进制表示中最右边一位是不是1，接着把输入的整数右移一位，此时原来处于
 * 倒数第二位的就被移动到最右边了，再判断是不是1；这样每次移动一位，直到整数变成0。
 * （但是，可能会造成死循环，输入负数可能会有问题，负数由补码表示，最高位符号位为1）
 */ 
int NumberOf1Error(int n) {
    int count = 0;
    while (n) {
        if (n & 1) 
            count++;
        n >>= 1;        // n 右移一位
    }
    return count;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", NumberOf1Error(n));
        printf("%d\n", NumberOf1(n));
        printf("%d\n", NumberOf1Nice(n));
    }
    return 0;
}
