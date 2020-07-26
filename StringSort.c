/**
 * Creation         :       2019.03.05 14:50
 * Last Reversion   :       2019.03.05 14:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串排序函数 (String sort function) P268
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>
#define N 100
#define MAXL 1000

/**
 * @brief StringSort 使用交换排序对字符串进行从小到大排序
 * @param char a[][MAXL]: 注意，这里函数的二维数组参数需要指定第二维大小
 */ 
void StringSort(char a[][MAXL], int n) {
    char temp[MAXL];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) > 0) {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
}


int main() {
    int n;
    char str[N][MAXL];
    printf("Please input the number of string :");
    scanf("%d", &n);
    getchar();  // 读走输入缓冲区中的回车
    for (int i = 0; i < n; i++) {
        printf("Please input %d string :", i+1);
        // scanf("%s", &str[i]);   // 如果允许字符串中包含空格，则改成使用 gets(srt); 对应的输出改成 puts(str);
        gets(str[i]);
    }
    StringSort(str, n);
    printf("The ascend result is :\n");
    for(int i = 0; i < n; i++)
        // printf("%s\n", str[i]);
        puts(str[i]);
    
    return 0;
}
