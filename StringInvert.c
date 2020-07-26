/**
 * Creation         :       2019.03.05 14:32
 * Last Reversion   :       2019.03.05 14:37
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 字符串反转函数 (String Invert function)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <string.h>
#define N 100

/**
 * @brief StringInvert
 * @param a[]
 */ 
void StringInvert(char a[]) {
    int len = strlen(a);
    char temp;
    for (int i = 0, j = len - 1; i <= j; i++, j--) {  // j start from len-1
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main() {
    char a[N];
    printf("Please input a string :");
    scanf("%s", &a);
    StringInvert(a);
    printf("The invert result is :%s\n", a);
    return 0;
}