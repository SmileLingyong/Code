/**
 * Creation         :       2019.04.04 14:50
 * Last Reversion   :       2019.03.04 15:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * EightQueen(2n皇后问题)
 * 问题描述：
 *    给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。
 * 现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，
 * 任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。   
 * 思路：
 *    其实就是在n皇后基础上改进的，按照n皇后思想，先放黑的，黑的都放好后再放白的，就是要多加一个
 * 判断已经放了黑的的位置就不能再放白的了。

输入格式
　　输入的第一行为一个整数n，表示棋盘的大小。
　　接下来n行，每行n个0或1的整数，
	如果一个整数为1，表示对应的位置可以放皇后，
	如果一个整数为0，表示对应的位置不可以放皇后。

输出格式
　　输出一个整数，表示总共有多少种放法。

样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2

样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
0
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int white[10], black[10], a[10][10], sum = 0, N = 0;

int CanPlaceBlack(int row) {
    for (int i = 0; i < row; i++) {
        if (black[row] == black[i] || (abs(black[row] - black[i]) == (row - i)))
            return 0;
    }
    return 1;
}

int CanPlaceWhite(int row) {
    for (int i = 0; i < row; i++) {
        if (white[row] == white[i] || (abs(white[row] - white[i]) == (row - i))) 
            return 0;
    }
    return 1;
}

void PutWhite(int row) {
    if (row >= N) {
        sum++;
    } else {
        for (int i = 0; i < N; i++) {
            white[row] = i;
            if (a[row][i] == 0 || black[row] == white[row]) // 该位置不能放或者已经放了黑的
                continue;
            if (CanPlaceWhite(row)) {
                PutWhite(row + 1);
            }
        }
    }
}

void PutBlack(int row) {
    if (row >= N) {
        PutWhite(0);
    } else {
        for (int i = 0; i < N; i++) {
            black[row] = i;
            if (a[row][i] == 0)
                continue;
            if (CanPlaceBlack(row)) {
                PutBlack(row + 1);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    PutBlack(0);
    printf("Sum = %d\n", sum);    
    return 0;
}