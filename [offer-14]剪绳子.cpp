/**
 * Creation         :       2019.04.05 17:09
 * Last Reversion   :       2019.04.05 22:00
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * IntegerBreak(剪绳子)
 * 题目描述
 *    给定一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为k[0],k[1],…,k[m]。请问k[0]* k[1] * … *k[m]可能的最大乘积是多少？
 * 例子：
 *    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 
 * 思路：
 *    问题是求最优解；
 *    整体的问题的最优解是依赖各个子问题的最优解；
 *    子问题之间还有互相重叠的更小的子问题；
 *    为避免子问题的重复计算，我们存储子问题的最优解。从上往下分析问题，从下往上求解问题。
 *    上面的几个条件可以看出，属于动态规划问题。
 * 对于第一刀，我们有n-1种可能的选择，
 *                  f(n)
 *            /       |            \
 *    f(1)*f(n-1)   f(2)*f(n-2)  ... f(n-1)*f(1)
 *     /      /       |    |           \       \
 * 
 * 可推导出 f(n) = max{ f(i) * f(n-i) }, 0 < i < n; 为递推公式
 * 并且 f(i) * f(n-i) = f(n-i) * f(i)，即只需要分析前面一半即可。
 * 
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))


/**
 * 方法一：动态规划
 *    递推公式为 (n) = max{ f(i) * f(n-i) }, 0 < i < n;
 * 分析好递推出口，然后就可以从下往上求解并保存中间结果(中间的重叠子问题)。
 */ 
int maxProductAfterCuttingDP(int n) {
    if (n < 2) 
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    // dp[] 数组存放从下往上计算的子问题的最优解。dp[i]表示把长度为i的绳子剪（或不剪）成若干段各段长度乘积的最大值，即 f(i)
    int *dp = (int*)malloc(sizeof(int) * (n + 1));  // 注意这里多开辟了一个空间，是为了让下标对应好
    dp[0] = 0;                                      // 分析递归出口
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i/2; j++) {            // 剪完前面的一半就够了，后面的一半和前面是对称的 
            dp[i] = max(dp[i], dp[j] * dp[i-j]);    // 让 dp[i] 保存所有的 f(j)*f(i-j) 中的最大值, 其中 1<=j<=i，自己分析一遍即明白了
        }
    }
    int res = dp[n];                                // 获取最后结果
    free(dp);
    return res;
}

/**
 * 方法二：贪心思想
 * (似乎存在问题，还是不用这个方法比较好！)
 */ 
int maxProductAfterCuttingGreedy(int n) {
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    // 尽可能多的剪成长度为3的绳子段
    int timesOf3 = n / 3;
    // 当绳子最后剩下的长度为 4 的时候，不能再减去长度为 3 的绳子段
    // 此时应该把绳子剪成长度为2的两段，因为 2x2 > 3x1
    if (n - timesOf3 * 3 == 1)
        timesOf3 -= 1;
    int timesOf2 = (n - timesOf3 * 3) / 2;
    return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));

}

int main() {
    int n;
    while (~scanf("%d", &n) && n != -999) {
        printf("%d\n", maxProductAfterCuttingDP(n));
        printf("%d\n", maxProductAfterCuttingGreedy(n));
    }
    return 0;
}