/**
 * Creation         :       2019.04.10 14:08
 * Last Reversion   :       2019.04.10 16:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 不使用乘法等实现累加
 * 题目描述
 *    求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等
 * 关键字及条件判断语句（A?B:C）。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

/**
 * 方法一：需利用逻辑与的短路特性实现递归终止
 */ 
int Sum_Solution(int n) {
    int ans = n;
    ans && (ans += Sum_Solution(n - 1));    // 当asn = 0时，&&结果为0，结束递归
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", Sum_Solution(n));
    return 0;
}