/**
 * Creation         :       2019.03.06 16:26
 * Last Reversion   :       2019.03.06 16:32
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * StringTransform 字符串转换
 *      任意输入一串字符,将下标为奇数的小写字母转换为大写(编号从0开始，若该位置上不是字母，
 * 则不转换)。举例：若输入abc4Efg，则应输出aBc4EFg(字符串数组)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <string.h>
#define N 1000

void StringTransform(char a[]) {
    int len = strlen(a);
    for (int i = 1; i < len-1; i+=2)    // 下标从0开始，编号也从0开始
        if (a[i] >= 'a' && a[i] <= 'z') 
            a[i] -= ('a' - 'A');
}

int main() {
    char a[N];
    printf("Please intpu a string: ");
    scanf("%s", &a);
    StringTransform(a);
    printf("The transform result is: %s\n", a);
    return 0;
}