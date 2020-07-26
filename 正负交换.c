/**
 * Creation         :       2019.03.06 18:56
 * Last Reversion   :       2019.03.06 19:08
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * PosAndNegExchange(正负交换)
 *      在一个整型数组a中既有负数又有正数，编写一个算法，将a中所有负数移到正数之前，
 * 要求其时间复杂度为O(n)，n为数组长度，并且只使用常数个辅助空间.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#define N 1000

void PosAndNegExchange(int a[], int n) {
    int i, j, temp;
    for (i = 0, j = n - 1; i <= j;) {
        if (a[i] < 0)
            i++;
        else if (a[j] >= 0)
            j--;
        else {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

int main() {
    int a[N], n;
    printf("How many numbers: ");
    scanf("%d", &n);
    printf("Please input n int number: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    PosAndNegExchange(a, n);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}