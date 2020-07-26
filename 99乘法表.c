/**
 * Creation         :       2018.11.18 16:30
 * Last Reversion   :       2018.11.18 16:37
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 99 multiplication table
 *      This function is to calculate 99 multiplication table.
 * -----------------------------------------------------------------
 * Crop right @ 2018 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>

void MultiplicationTable() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%2d ", j, i, j * i);
        }
        printf("\n");
    }
}

int main() {
    MultiplicationTable();
    return 0;
}