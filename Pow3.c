/**
 * Creation         :       2019.03.03 23:39
 * Last Reversion   :       2019.03.03 23:39
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 快速幂 Pow3
 *      基本原理是二进制，要知道，任何一个整数n，都能用二进制来表示。
 *  那么对于 a^n，我们将n用二进制来表示。
 *      例如： a^156, 其中156(10) = 10011100(2)，那么：
 *  A = a^156 = a^(10011100)
 *    = a^((2^7)*1 + (2^6)*0 + (2^5)*0 + (2^4)*1 + (2^3)*1 + (2^2)*1 + (2^1)*0 + (2^0)*0)
 *    = a^((2^7)*1) * a^((2^6)*0) * a^((2^5)*0) * a^((2^4)*1) * a^((2^3)*1) * a^((2^2)*1) * a^((2^1)*0) * a^((2^0)*0)
 *  (看一下手机中的推到过程就明白了) 
 * -----------------------------------------------------------------
 * Reference: https://blog.csdn.net/MosBest/article/details/69264953
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h> 

/**
 * @brife Pow3 快速幂求 a^n
 * @param int a
 * @param int n
 * @return 
 */ 
long long int Pow3(int a, int n) {
    long long int ans = 1;
    long long int base = a;
    while(n != 0){
        if (n & 1) {
            ans *= base;
        }
        base *= base;
        n /= 2; // equal to n >>= 1
    }
    return ans;
}

int main() {
    int a, n;
    printf("Please input a and n of the formula a^n to be calculated: ");
    while(scanf("%d %d", &a, &n) != EOF){
        printf("%d^%d = %lld\n", a, n, Pow3(a, n));
        printf("Please input a and n of the formula a^n to be calculated: ");
    }
    return 0;
}