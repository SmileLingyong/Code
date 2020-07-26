/**
 * Creation         :       2019.03.04 23:43
 * Last Reversion   :       2019.03.04 23:43
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串链接函数 (String cat function)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <string.h>
#define N 100

void StrCat(char dstStr[], char srcStr[]) {
    int i = 0, len = 0;
    while (dstStr[i++] != '\0')
        len++;
    i = 0;
    while (srcStr[i] != '\0'){
        dstStr[len] = srcStr[i];
        i++;
        len++;
    }
    dstStr[len] = '\0';
}

void PStrCat(char *dstStr, char *srcStr) {
    int len = 0;
    while (*dstStr != '\0') 
        dstStr++;
    while (*srcStr != '\0') {
        *dstStr++ = *srcStr++;
    }
    *dstStr = '\0';
}

int main() {
    char a[N], b[N], c[N];
    printf("Please input src string :");
    scanf("%s", &a);
    printf("Please input dst string :");
    scanf("%s", &b);
    strcpy(c, a);

    StrCat(a, b);
    PStrCat(c, b);
    printf("The result is :%s\n", a);
    printf("The result is :%s\n", c);
    return 0;
}