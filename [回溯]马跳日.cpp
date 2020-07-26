/**
 * Creation         :       2019.04.04 14:50
 * Last Reversion   :       2019.03.04 15:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 题目描述：
 *    在半个中国象棋棋盘上,马在左下角(1, 1)处, 马走日字，而且只能往右走，
 * 不能向左，可上可下，求从起点到(m, n)处有几种不同的走法（函数的递归调用）
 * 其中，1<= m <=5， 1<= n <=9
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>

/**
 * 普通的DFS，没有剪枝(直接记这个模板就行)
 */ 
int horse(int x1, int y1, int x2, int y2) {
    int sum = 0;
    if (x1 >= 1 && x1 <= x2 && x1 <= 5 && y1 >= 1 && y1 <= y2 && y1 <= 9) {
        if (x1 == x2 && y1 == y2) 
            return 1;
        else {
            sum = sum + horse(x1 - 1, y1 + 2, x2, y2)
                      + horse(x1 + 1, y1 + 2, x2, y2)
                      + horse(x1 - 2, y1 + 1, x2, y2)
                      + horse(x1 + 2, y1 + 1, x2, y2);
        }
    }
    return sum;
}

/**
 * 做了剪枝处理
 */ 
int horseII(int x1, int y1, int x2, int y2) {
    int sum = 0;
    if (y1 > y2 || (y1 == y2 && x1 != x2))  // 起点和终点不能在同一列
        return 0;
    else if (x1 == x2 && y1 == y2)  // 走到了终点，返回1，然后递归回去
        return 1;
    else {
        if (x1 - 1 >= 1 && y1 + 2 <= 9) sum += horse(x1 - 1, y1 + 2, x2, y2);
        if (x1 - 2 >= 1 && y1 + 1 <= 9) sum += horse(x1 - 2, y1 + 1, x2, y2);
        if (x1 + 2 <= 5 && y1 + 1 <= 9) sum += horse(x1 + 2, y1 + 1, x2, y2);
        if (x1 + 1 <= 5 && y1 + 2 <= 9) sum += horse(x1 + 1, y1 + 2, x2, y2);
        return sum;
    }
}

int main() {
    int m, n;
    printf("请输入目的地址：\n");
    scanf("%d %d", &m, &n);
    while (m > 5 || m < 1 || n > 9 || n < 1) {  // 半个中国象棋的边界
        printf("输入错误，请重新输入：");
        scanf("%d%d", &m, &n);
    }
    printf("目的结果数为%d\n", horse(1, 1, m, n));
    printf("目的结果数为%d\n", horseII(1, 1, m, n));
    getchar();  // pause to show sum
    getchar();
    return 0;
}
