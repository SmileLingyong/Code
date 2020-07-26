/**
 * Creation         :       2019.03.04 21:10
 * Last Reversion   :       2019.03.04 21:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 输入一行字符，统计其中英文字符、数字、空格和其他字符的个数
 * Enter a line of characters to count the number of letter, numbers, spaces, and other characters.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#define N 1000
int main() {
    char str[N];
    int i, letter = 0, digit = 0, space = 0, others = 0;
    printf("Please input a string:");
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            letter++;
        else if (str[i] >= '0' && str[i] <= '9')
            digit++;
        else if (str[i] == ' ')
            space++;
        else
            others++;
    printf("English character: %d\n", letter);
    printf("digit character: %d\n", digit);
    printf("space: %d\n", space);
    printf("other character: %d\n", others);
    return 0;
}