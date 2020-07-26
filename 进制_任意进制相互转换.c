/**
 * Creation         :       2019.03.03 16:07
 * Last Reversion   :       2019.03.03 16:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 任意进制相互转换
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NumToTen(char a[], int B);  //将输入的数字转换成十进制数
void TenChange(int m, int B);  	//将转换好了的十进制数转换为所需进制数

/**
 * @brief NumToTen: 将输入的数字转换成十进制数
 * @param a: 待转换的数		
 * @param B: 待转换数所属进制类别
 * @return sum: 返回转换为十进制的数
 */
int NumToTen(char a[], int B) {
    int len, i, num;
    int sum = 0;
    len = strlen(a);  //求得字符串长度
    for (i = 0; i < len; i++) {
        if (a[i] >= '0' && a[i] <= '9')
            num = a[i] - '0';
        else if (a[i] >= 'A' && a[i] <= 'F')
            num = a[i] - 'A' + 10;
        sum = sum * B + num;
    }
    return sum;
}

/**
 * @brief TenChange: 将十进制转换为任意进制
 * @param m: 十进制数
 * @param B: 转换成
 */ 
void TenChange(int n, int B) {
    int m;
    if (n) {
        TenChange(n / B, B);
        m = n % B;
        if (m < 10)
            printf("%d", m);  		//小于10直接输出
        else
            printf("%c", m + 55);  	//大于10转换成字符输出
    }
}
int main() {
    int B, b;
    char a[20];
    printf("请输入待转换数的进制（2-16）：");
    do {
        scanf("%d", &B);
    } while (B < 2 || B > 16);
    printf("请输入待转换数：");
    getchar();
    gets(a);               	 //将输入的n进制数存放在数组a中
    int n = NumToTen(a, B);  //将输入的数字转换成十进制数
    printf("请输入需要转成几进制数（2-16）：");
    do {
        scanf("%d", &b);
    } while (B < 2 || B > 16);
    printf("%d进制数 %s 转换为 %d进制数的结果为：", B, a, b);
    TenChange(n, b);  //将十进制数转换为所需进制数
    printf("\n");
    return 0;
}