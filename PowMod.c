/**
 * Creation         :       2019.03.04 11:39
 * Last Reversion   :       2019.03.04 11:39
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 快速幂取模 PowMod
 *      在快速幂的基础上取模长而已: (a^n)%c = ((a%c)^n)%c
 * -----------------------------------------------------------------
 * Reference: https://wenku.baidu.com/view/d65f294702768e9951e73883.html
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

/**
 * @brife PowMod 快速幂取模 (a^n)%c = ((a%c)^n)%c
 * @param int a
 * @param int n
 * @param int c
 * @return 
 */ 
long long int PowMod(int a, int n, int c) {
    long long ans = 1;
    long long base = a % c;
    while(n){
        if (n & 1)
            ans = (ans * base) % c;
        base = (base * base) % c;
        n /= 2;     // n >>= 1;
    }
    return ans;
}

int main() {
    int a, n, c;
    printf("Please intpu a n c of (a^n)%%c: ");
    while(scanf("%d %d %d", &a, &n, &c) != EOF) {
        printf("(%d^%d) %% %d = %lld\n", a, n, c, PowMod(a, n, c));
        printf("Please intpu a n c of (a^n)%%c: ");
    }
    return 0;
}