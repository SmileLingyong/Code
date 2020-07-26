/**
 * Creation         :       2019.04.04 17:35
 * Last Reversion   :       2019.04.04 18:02
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    假设国际象棋盘有5*5共有25个格子。设计一个程序，使棋子从初试位置（棋盘格编号为1的位置）开始跳马，
 * 能够把棋盘的格子全部走一遍，每个格子只允许走一次，要求：
 * （1）输出一个解（用二维数组来记录马跳的过程，即【步号，棋盘格编号】，左上角为第1步起点）
 * （2）求总共有多少解？
 * 棋盘格编号为：
 *      1   2   3   4   5
 *      6   7   8   9   10
 *      11  12  13  14  15
 *      16  17  18  19  20
 *      21  22  23  24  25
 * 思想：
 *    回溯思想 (和八皇后一个思路)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
int a[5][5];                                // 棋盘
int b[5][5] = {0};                          // 用于标记棋盘对应位置是否已走过
int step[26] = {0}, step_num = 0, sum = 0;  // 用于记录每步走过的位置，sum为总共有多少总跳法
                                            // 要多申请一个step空间，因为step下标从1开始计算
void Init(int a[][5]) {                     // 初始化棋盘
    int k = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = k++;
        }
    }
}

/**
 * 判断该跳是否可行（或者直接写到那个Check函数之中中）
 */
int Check(int x, int y) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5 || b[x][y] == 1)  // 不要忘了判断该位置是否已走过
        return 0;
    else
        return 1;
}

/**
 * 探寻可走的路
 */
void Search(int x, int y) {
    if (Check(x, y)) {               // 如果该跳可行
        step[++step_num] = a[x][y];  // step下标从1开始
        if (step_num == 25) {        // 若25个均跳好了
            sum++;
            printf("\nThe %d Jump:\n", sum);
            for (int i = 1; i <= 25; i++) {
                printf("[%d,%d]\n", i, step[i]);
            }
        }
        b[x][y] = 1;                // 标记该位置已经走过了
        Search(x + 1, y + 2);       // 递归调用，寻找下一跳
        Search(x + 1, y - 2);
        Search(x - 1, y + 2);
        Search(x - 1, y - 2);
        Search(x + 2, y + 1);
        Search(x + 2, y - 1);
        Search(x - 2, y + 1);
        Search(x - 2, y - 1);
        step_num--;                 // 若寻找的下一跳都不可行，取消这一步，回退到上一步
        b[x][y] = 0;                // 把这步设置标记未走过
    }
}

int main() {
    Init(a);                        // 初始化棋盘
    Search(0, 0);
    printf("\nSum = %d", sum);
    return 0;
}
