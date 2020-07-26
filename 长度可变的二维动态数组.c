/**
 * Creation         :       2019.03.06 11:06
 * Last Reversion   :       2019.03.06 11:
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 长度可变的二维动态数组 P318
 *      输入m个班学生（每班n个学生）的某门课成绩，计算并输出最高分，
 * 同时指出有该最高分成绩的学生是第几个班的第几个学生。班级数和每班学生数由键盘输入。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief InputArray: 输入n个学生成绩
 * @param int *p: 二维数组列指针变量，传入数组的首地址初始化
 * @param int m: 数组的行数
 * @param int n: 数组的列数
 */
void InputArray(int *p, int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Please input %d class %d students\n", i+1, n);
        for (int j = 0; j < n; j++) 
            scanf("%d", p+i*n+j);       // equals to &p[i*n+j]
    }
}

void GetMaxScore(int *p, int m, int n, int *max_score, int *max_class, int *max_id) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if (*max_score < *(p+i*n+j)) {  // equals to p[i*n+j]
                *max_score = *(p+i*n+j);
                *max_class = i+1;
                *max_id = j+1;
            }
}
int main() {
    int m, n;
    int *p = NULL;
    int max_score = 0, max_class = 0, max_id = 0;
    printf("How many classes?\n");
    scanf("%d", &m);
    printf("How many students in a class?\n");
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int) * m * n);  // 向系统申请内存
    if (p == NULL) {
        printf("No enouth memory!\n");
        exit(1);
    }

    InputArray(p, m, n);

    GetMaxScore(p, m, n, &max_score, &max_class, &max_id);

    printf("Max score is %d\nclass %d\nid %d\n", max_score, max_class, max_id);

    free(p);
    return 0;
}
