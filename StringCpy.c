/**
 * Creation         :       2019.03.04 21:18
 * Last Reversion   :       2019.03.04 21:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串拷贝函数 (String copy function)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#define N 100
void StrCpy(char dstStr[], char srcStr[]);
void PStrCpy(char *dstStr, char *srcStr);

int main() {
    char a[N], b[N], c[N];
    printf("Please input a string :");
    scanf("%s", &a);

    StrCpy(b, a);
    PStrCpy(c, a);
    
    printf("The copy is %s:\n", b);
    printf("The copy is %s:\n", c);
    return 0;
}

/**
 * @brief StrCpy: 使用字符数组做为函数参数，实现字符串复制
 */ 
void StrCpy(char dstStr[], char srcStr[]) {
    int i = 0;
    while(srcStr[i] != '\0'){
        dstStr[i] = srcStr[i];
        i++;
    }
    dstStr[i] = '\0';    

    // Equivalent to the above
    // for (int i = 0; srcStr[i] != '\0'; i++)
    //     dstStr[i] = srcStr[i];
    // dstStr[i] = '\0';    
}

/**
 * @brief PStrCpy: 使用字符指针做为函数参数，实现字符串复制
 */ 
void PStrCpy(char *dstStr, char *srcStr) {
    while(*srcStr != '\0')
        *dstStr++ = *srcStr++;  // equals to *dstStr = *srcStr; dstStr++; srcStr++;
    *dstStr = '\0';    

    // Equivalent to the above
    // for (; *srcStr != '\0'; srcStr++, dstStr++)
    //     *dstStr = *srcStr;
    //  *dstStr = '\0';  
}