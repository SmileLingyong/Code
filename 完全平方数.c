/**
 * Creation         :       2019.03.06 17:00
 * Last Reversion   :       2019.03.06 
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * CompleteSquareNum(完全平方数+)
 *      按要求输出：在三位整数(100至999)中寻找符合条件的整数并依次从小到大存入数组中；
 * 他既是完全平方数,又是两位数字相同，例如144,676等
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <math.h>

int IsSquare(int num) {
    int sqr = (int)(sqrt(num * 1.0));
    return (sqr*sqr == num || (sqr+1)*(sqr+1) == num);
}

int IsTwoSame(int num) {
    int digit0, digit1, digit2;

    digit0 = num%10;
	digit1 = (num/10)%10;
	digit2 = (num/100)%10;
    return (digit0==digit1 || digit0==digit2 || digit1==digit2);
}

int main() {   
    int a = 0, b = 0, c = 0; 
    for(int i = 100; i <= 999; i++)
        if (IsSquare(i) && IsTwoSame(i)) 
            printf("%d\n", i);
    return 0;
}