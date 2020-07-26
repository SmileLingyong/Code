/**
 * Creation         :       2019.03.03 16:03
 * Last Reversion   :       2019.03.03 16:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 将十进制转换为任意进制 (Convert decimal to arbitrary radix)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>

#define N 1000

/**
 * @brief DecimalChange: 十进制转换为任意进制
 * @param int n: 十进制数
 * @param int B: 需要转换成的进制(注意：16进制需要特别处理)
 */
void DecimalChange(int n, int B) {
    int res[N], i = 0;
    while (n / B != 0) {   // 即利用栈的思想
        res[i++] = n % B;  // 把余数存入数组之中
        n = n / B;
    }
    res[i] = n % B;
    for (int j = i; j >= 0; j--) {  // 从栈依次取出余数
        if (res[j] < 10)
            printf("%d", res[j]);
        else 
            printf("%c", res[j] + 55);
    }
}

/**
 * @brief DecimalChange: 十进制转换为任意进制（回溯法）
 * @param int n: 十进制数
 * @param int B: 需要转换成的进制(注意：16进制需要特别处理)
 */
void DecimalChangeBackTracking(int n, int B) {
    int m = 0;
    if (n) {
        DecimalChangeBackTracking(n / B, B);
        m = n % B;
        if (m < 10) 
            printf("%d", m);        //小于10直接输出
        else
            printf("%c", m + 55);   //大于10转换成字符输出
    }
}


int main() {
    int n, B;
    printf("Please input decimal and target radix:");
    while(scanf("%d %d", &n, &B) != EOF){
        DecimalChange(n, B);
        printf("\n");
        DecimalChangeBackTracking(n, B);
        printf("\nPlease input Decimal and Target radix:");
    }
}