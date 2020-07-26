/**
 * Creation         :       2019.03.04 21:40
 * Last Reversion   :       2019.03.04 21:47
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串长度计算函数 (String length function)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 100

int StrLen(char str[]) {
    int i = 0, len = 0;
    while(str[i++] != '\0')
        len++;
    return len;
}

int PStrLen(char *str) {
    int i = 0, len = 0;
    while(*str++ != '\0')   // equals to *str != '\0'; str++;
        len++;
    return len;
}

int main() {
    int a[N];
    printf("Please input a string :");
    scanf("%s", &a);
    printf("string length is %d\n", StrLen(a));
    printf("string length is %d\n", PStrLen(a));
    return 0;
}