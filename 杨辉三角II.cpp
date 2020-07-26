/**
 * Creation         :       2019.04.04 21:12
 * Last Reversion   :       2019.03.04 21:25
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 杨慧三角(YangHuiTriangleI)
 * 思路：
 *    先定义一个二维数组：a[N][N]，略大于要打印的行数。再令两边的数为1,
 * 即当每行的第一个数和最后一个数为1。a[i][0]=a[i][i-1]=1，n为行数。除
 * 两边的数外，任何一个数为上两顶数之和，即a[i][j]=a[i-1][j-1]+a[i-1][j]。
 * 最后输出杨辉三角。

请输入要打印的行数：10
10行杨辉三角如下：
1
1     1
1     2     1
1     3     3     1
1     4     6     4     1
1     5    10    10     5     1
1     6    15    20    15     6     1
1     7    21    35    35    21     7     1
1     8    28    56    70    56    28     8     1
1     9    36    84   126   126    84    36     9     1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 14
int main() {
    int i, j, k, n = 0, a[N][N];        // 定义二维数组a[14][14]
    while (n <= 0 || n >= 13) {         // 控制打印的行数不要太大，过大会造成显示不规范
        printf("请输入要打印的行数：");
        scanf("%d", &n);
    }
    printf("%d行杨辉三角如下：\n", n);
    for (i = 1; i <= n; i++)
        a[i][1] = a[i][i] = 1;          // 两边的数令它为1，因为现在循环从1开始，就认为a[i][1]为第一个数
            
    for (i = 3; i <= n; i++)
        for (j = 2; j <= i - 1; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];      // 除两边的数外都等于上两顶数之和
                     
    for (i = 1; i <= n; i++) {
        // for (k = 1; k <= n - i; k++)
        //     printf(" ");                // 这一行主要是在输出数之前打上空格占位，让输出的数更美观
        for (j = 1; j <= i; j++) {      // j<=i的原因是不输出其它的数，只输出我们想要的数
            if (j != 1)
                printf("%6d", a[i][j]);
            else 
                printf("%d", a[i][j]);
        }
        printf("\n");                   // 当一行输出完以后换行继续下一行的输出
    }
    printf("\n");
    return 0;
}