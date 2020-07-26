/**
 * Creation         :       2019.03.03 23:39
 * Last Reversion   :       2019.03.03 23:39
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 二分幂 Pow
 *      比如求 a^n，如果知道了 a^(n/2) 次方的话，再来个平方就可以了。
 *  即：
 *      如果n是偶数，则 A=a^(n/2);     A=A*A
 *      如果n是奇数，则 A=a^((n-1)/2); A=a*A*A
 * -----------------------------------------------------------------
 * Reference: https://blog.csdn.net/MosBest/article/details/69264953
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>

/**
 * @brief Pow:  求a的n次幂
 * @param int a
 * @param int n
 * @return 
 */ 
long long int Pow(int a, int n) {
    if (n == 0)  return 1;
    if (n == 1)  return a;
    long long int ans = Pow(a, n/2);
    ans *= ans;
    if (n % 2 == 1)
        ans *= a;
    return ans;
}

int main() {
    int a, n;
    printf("Please input a and n of the formula a^n to be calculated: ");
    while(scanf("%d %d", &a, &n) != EOF){
        printf("%d^%d = %lld\n", a, n, Pow(a, n));
        printf("Please input a and n of the formula a^n to be calculated: ");
    }
    return 0;
}