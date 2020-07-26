/**
 * Creation         :       2019.03.22 10:10
 * Last Reversion   :       2019.03.08 10:25
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
reOrderArray(调整数组顺序，使奇数位于偶数前面)
题目描述
   输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于
数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间
的相对位置不变。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 思路：新建一个数组b，遍历一遍数组a，把奇数存入数组b，
 * 然后再遍历一遍a，把偶数存入数组b，最后用b覆盖元数组即可。
 */ 
void reOrderArray(vector<int> &array) {
    vector<int> b;
    for (int i = 0; i < array.size(); i++) 
        if (array[i] % 2 == 1)
            b.push_back(array[i]);
    for (int i = 0; i < array.size(); i++)
        if (array[i] % 2 == 0)
            b.push_back(array[i]);
    array = b;
}

/**
 * 方法二：类似冒泡排序，从后往前开始遍历，前偶后奇就交换（自己手动Debug一下就明白了）
 */ 
void reOrderArrayII(vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = array.size() - 1; j > i; j--) {
            if (array[j - 1] % 2 == 0 && array[j] % 2 == 1) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    vector<int> a;
    printf("Please input a int number n: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    reOrderArray(a);
    for (int i = 0; i < a.size(); i++) 
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}