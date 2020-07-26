/**
 * Creation         :       2019.03.04 11:39
 * Last Reversion   :       2019.03.04 11:39
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 快速乘取模 PowModMatirx
 *      思想是类似的
 * -----------------------------------------------------------------
 * Reference: https://blog.csdn.net/MosBest/article/details/69264953
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define ll long long int

ll PowModMatirx(ll a, ll n, ll mod) {
    int sum = 0;
    ll base = 1;
    ll ans = a;
    while (n) {
        if (n & 1) {
            sum = (sum + ans * base) % mod;
        }
        base = (base * 2) % mod;
        n /= 2;
    }
    return sum;
}

int main() {
    ll a, n, mod;
    printf("Please input the int num of a n mod: \n");
    scanf("%lld %lld %lld", &a, &n, &mod);
    printf("%lld * %lld %% %lld = %lld\n", a, n, mod, PowModMatirx(a, n, mod));
    return 0;
}