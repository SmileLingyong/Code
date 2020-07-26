/**
 * Creation         :       2019.03.05 16:29
 * Last Reversion   :       2019.03.05 17:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 二维指针和二维数组 (Pointer and array two dim) P299 (不懂就看这页二维数组的那个图)
 *      输入一个3行4列的二维数组，然后输出这个二维数组的元素值。
 * 共可以有3中方式：
 *      ①使用二维数组作为函数形参（注意这里必须显示的指定数组第二维(列)的长度）
 *      ②使用二维数组的行指针作为函数形参
 *      ③使用二维数组的列指针做为函数形参
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 4

/**
 * @brief InputArray: 使用二维数组作为函数形参
 * @param int a[][N]: 二维数组(要显示指定二维数组列的大小)
 * @param int m: 二维数组的行数
 * @param int n: 二维数组的列数
 */
void InputArray(int a[][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void OutputArray(int a[][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief PRowInputArray: 使用二维数组的行指针作为函数形参
 * @param int (*p)[N]: 定义了一个可以指向含有N个元素的一维整型数组的指针变量，即定义了一个二维数组的行指针，它所指向的二维数组的每一行有N个元素(N与n是同一个数)
 * @param int m: 二维数组的行数
 * @param int n: 二维数组的列数
 */
void PRowInputArray(int (*p)[N], int m, int n) {    // 二维数组行指针定义并初始化 ==> 定义：int (*p)[N]; 初始化: p = a; 或 p=&a[0]; 即获取二维数组第0行的地址
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {       // 通过行指针指向二维数组a的元素地址&a[i][j] => &p[i][j] = p[i]+j = *(p+i)+j
            scanf("%d", *(p+i)+j);   
        }
    }
}

void PRowOutputArray(int (*p)[N], int m, int n) {   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(p+i)+j));     // 通过行指针引用二维数组a的元素a[i][j] => p[i][j] = *(p[i]+j) = *(*(p+i)+j) = (*(p+i))[j]
        }
        printf("\n");
    }
}

/**
 * @brief PColInputArray: 使用二维数组的列指针作为函数形参
 * @param int *p: 定义了一个二维数组的列指针
 * @param int m: 二维数组的行数
 * @param int n: 二维数组的列数
 */
void PColInputArray(int *p, int m, int n) {     // 定了了二维数组的列指针，并对齐初始化，可以有3种初始化方式: p = a[0]; <--> p = *a = *(&a[0]); <--> p = &a[0][0];   因为a为数组名，代表第一个元素a[0]的地址&(a[0])
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", p+i*n+j);               // 通过列指针指向二维数组a的元素地址&a[i][j] => p+i*n+j = p[i*n+j]
        }
    }
}

void PColOutputArray(int *p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(p+i*n+j));          // 列指针引用二维数组a的元素a[i][j] => *(p+i*n+j) = *p[i*n+j]
        }
        printf("\n");
    }
}

int main() {
    int a[3][4];
    printf("Please input 3*4 numbers: \n");
    // 使用二维数组作为函数形参
    // InputArray(a, 3, 4);        // 向函数传递二维数组的第0行的地址
    // OutputArray(a, 3, 4);       // 向函数传递二维数组的第0行的地址

    // 使用二维数组的行指针作为函数形参
    // PRowInputArray(a, 3, 4);    // 向函数传递二维数组的第0行的地址
    // PRowOutputArray(a, 3, 4);

    // 使用二维数组的列指针作为函数形参
    PColInputArray(*a, 3, 4);       // 向函数传递二维数组的第0行第0列的地址
    PColOutputArray(*a, 3, 4);

    return 0;
}