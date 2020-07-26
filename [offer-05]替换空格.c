/**
 * Creation         :       2019.03.09 10:02
 * Last Reversion   :       2019.03.09 10:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * ReplaceSpace(替换空格)
 * 题目描述
 *    请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We
 * Are Happy。 则经过替换之后的字符串为We%20Are%20Happy。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief:重新开辟一个新的字符串数组用来备份原来的字符串数组，然后再将替换后的一一覆盖原来的字符串数组
 *        时间复杂度O(n), 空间复杂度O(n)
 */
void replaceSpace(char *str, int length) {
    if (str == NULL || length <= 0) return;

    char *des = (char *)malloc(sizeof(char) * length);
    strcpy(des, str);

    for (int i = 0; i < length; i++) {
        if (*(des + i) == ' ') {
            *str++ = '%';
            *str++ = '2';
            *str++ = '0';
        } else {
            *str++ = *(des + i);
        }
    }
    *str = '\0';
    free(des);
}

/**
 * @brief: 使用的指针的方式遍历，在原有的字符串上进行修改，先计算替换后的字符串长度，然后设置两个指针，分别指向替换前字符串的末尾p1，和替换后字符串的末尾p2
 *         然后从后往前做替换：
 *              如果p1指向的内容不是空格，则将p1指向的内容复制到p2，p1--; p2--;；
 *              如果p1直线的内容是空格，则将空格替换成%20，p2边替换边--; p1--;
 *         直至遍历完整个数组。
 */ 
void replaceSpace2(char *str, int length) {
    if (str == NULL || length <= 0) return;

    int i, spaceNum = 0, newLength = 0;
    int pOri = 0, pNew = 0;     // 分别指向原来的字符串末尾和替换后字符串末尾

    // 计算替换后的字符串长度
    for (i = 0; i < length; i++)
        if (*(str+i) == ' ')    // 注意这里不要写成str++; 这是错误的，很容易错！
            spaceNum++;
    newLength = length + 2 * spaceNum;
    pOri = length;
    pNew = newLength;

    while (pOri >= 0) {
        if (*(str+pOri) != ' ') {
            *(str+pNew) = *(str+pOri);
            pOri--;
            pNew--; 
        } else {
            *(str+pNew--) = '0';
            *(str+pNew--) = '2';
            *(str+pNew--) = '%';
            pOri--;
        }
    }
}

/**
 * 使用数组下标的形式遍历
 */ 
void replaceSpace3(char *str, int length) {
    if (str == NULL || length <= 0) return;

    int i, spaceNum = 0, newLength = 0;
    int pOri = 0, pNew = 0;  // 分别指向原来的字符串末尾和替换后字符串末尾

    // 计算替换后的字符串长度
    for (i = 0; i < length; i++)
        if (str[i] == ' ') 
            spaceNum++;
    newLength = length + 2 * spaceNum;
    pOri = length;
    pNew = newLength;

    while (pOri >= 0) {
        if (str[pOri] != ' ') {
            str[pNew--] = str[pOri--];
        } else {
            str[pNew--] = '0';
            str[pNew--] = '2';
            str[pNew--] = '%';
            pOri--;
        }
    }
}

int main() {
    char str[] = "We Are Happy ";
    replaceSpace2(str, strlen(str));
    printf("%s\n", str);
    return 0;
}
