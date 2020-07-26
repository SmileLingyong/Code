/**
 * Creation         :       2019.03.16 14:13
 * Last Reversion   :       2019.03.16 14:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 判断一个整数是否是回文数 (IsPalindrome)
 *      回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 *      输入: 121
 *      输出: true
 * 示例 2:
 *      输入: -121
 *      输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 示例 3:
 *      输入: 10
 *      输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define N 12


/**
 * 方法一：用回文字符串思路，将int转换为字符串，然后在做处理
 */ 
bool IsPalindrome1(int x) {
    if (x < 0) return false;
    char str[N];
    int i = 0, j = 0, len = 0;
    while (x) {
        str[i] = x % 10;
        x /= 10;
        i++;
    }
    len = i;
    for (i = 0, j = len - 1; i < j; i++, j--) 
        if (str[i] != str[j])
            return false;
    return true;
}

/**
 * 方法二：使用回文字符串的思路，使用vector操作
 */ 
bool IsPalindrome2(int x) {
    if( x < 0) return false;
    int i, j;
    vector<char> str;
    while (x) {
        str.push_back(x % 10);
        x /= 10;
    }
    for (i = 0, j = str.size()-1; i < j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}

/**
 * 方法二：官方解答没细看
 */ 
bool IsPalindrome3(int x) {

}

int main() {
    int x;
    printf("Please input a int number: ");
    scanf("%d", &x);
    if(IsPalindrome2(x)) 
        printf("%d is a palin drome number.\n", x);
    else
        printf("%d is not a palin drome number.\n", x);
    return 0;
}