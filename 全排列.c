/**
 * Creation         :       2019.04.08 21:40
 * Last Reversion   :       2019.04.09 10:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 全排列
 * 思路：
 *    123的全排列有123、132、213、231、312、321这六种。首先考虑213和321
 * 这二个数是如何得出的。显然这二个都是123中的1与后面两数交换得到的。然后
 * 可以将123的第二个数和每三个数交换得到132。同理可以根据213和321来得231
 * 和312。因此可以知道——全排列就是从第一个数字起每个数分别与它后面的数字交
 * 换。找到这个规律后，递归的代码就很容易写出来了
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

/* 交换两个数据 */
void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void FullyArrange(int str[], int index, int str_len) {
    if (index == str_len) {
        /* 输出当前的排列 */
        for (int i = 0; i < str_len; i++) {
            printf("%d ", str[i]);
        }
        printf("\n");
    } else {
        for (int j = index; j < str_len; j++) {     // 第index个数分别与它后面的数字交换就能得到新的排列
            Swap(&str[index], &str[j]);
            FullyArrange(str, index + 1, str_len);
            Swap(&str[index], &str[j]);             // 保证每一层递归后保持上一层的顺序  
        }
    }
}
int main() {
    int a[] = {1, 2, 3};
    int str_len = sizeof(a) / sizeof(int);
    FullyArrange(a, 0, str_len);
    return 0;
}