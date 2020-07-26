/**
 * Creation         :       2019.03.05 14:50
 * Last Reversion   :       2019.03.05 14:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串排序函数(使用指针数组) (String sort function) P370
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>
#define N 100       /* 字符串个数 */
#define MAXL 1000   /* 字符串最大长度 */

/**
 * @brief StringSortPointer 用指针数组作函数参数，采用交换法实现字符串按字典顺序排序
 * @param char *ptr[]: 指针数组
 */ 
void StringSortPointer(char *ptr[], int n) {
    char *temp = NULL;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ptr[i], ptr[j]) > 0) {   // 交换指向字符串的指针
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}


int main() {
    int n;
    int debug_print = 1; // 是否打印输出调试信息
    char str[N][MAXL];
    char *pStr[N];       // 定义字符指针数组
    printf("Please input the number of string :");
    scanf("%d", &n);
    getchar();          // 读走输入缓冲区中的回车
    for (int i = 0; i < n; i++) {
        printf("Please input %d string :", i+1);
        pStr[i] = str[i];   // 让pStr[i]指向二维字符数组str的第i行，即第i个字符串
        gets(pStr[i]);      // 输入第i个字符串到pStr[i]指向的内存 (看打印信息就会明白)
    }

    if (debug_print) {
        /* Before sorted */
        printf("\nBefore sorted: \n");
        printf("pStr[i] \t\tpStr[i] point to \tstr[i]\n");
        for (int i = 0; i < n; i++) {
            printf("%-10p", pStr[i]);   // 输出排序前的n个字符串的首地址
            printf("\t\t%s\t\t%s\n", pStr[i], str[i]);  // 输出排序前的n个字符
        }
    }

    StringSortPointer(pStr, n);     // 排序结果只改变了原来指针数组pStr的元素指向，并未改变二维字符数组str中的字符串的排列顺序

    if (debug_print) {
        /* After sorted */
        printf("\nAfter sorted: \n");
        printf("pStr[i] \t\tpStr[i] point to \tstr[i]\n");
        for (int i = 0; i < n; i++) {
            printf("%-10p", pStr[i]);   // 输出排序后的n个字符串的首地址
            printf("\t\t%s\t\t%s\n", pStr[i], str[i]);  // 输出排序后的n个字符
        }   
    } 

    printf("\nThe ascend result is :\n");
    for(int i = 0; i < n; i++) {
        puts(pStr[i]);      // 输出排序后的指针数组所指向的字符串
    }
    return 0;
}
