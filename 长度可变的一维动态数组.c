/**
 * Creation         :       2019.03.06 11:02
 * Last Reversion   :       2019.03.06 11:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 长度可变的一维动态数组 P316
 *      输入某班学生的某门课成绩，计算并输出平均分。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief InputArray: 输入n个学生成绩
 * @param int *p: 一维数组指针变量，传入数组的首地址初始化
 * @param int n: 数组的大小
 */ 
void InputArray(int *p, int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", p+i);     // equals to scanf("%d", &p[i]);
}

double Average(int *p, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += *(p+i);        // equals to sum += p[i];
    return (double)sum / n;    
}

int main() {
    int n;
    int *p = NULL;
    double aver = 0.0f;

    printf("Please intpu the student number: ");
    scanf("%d", &n);

    p = (int*)malloc(sizeof(int) * n);  // 向系统申请内存
    if (p == NULL) {    // 确保指针使用的是非空指针，当p为空指针时结束程序运行
        printf("No enough memory!\n");
        exit(1);
    }

    printf("Please intpu each student score: \n");
    InputArray(p, n);
    aver = Average(p, n);
    printf("The average score is: %.2f\n", aver);

    free(p);            // 释放向系统申请的内存！！！(不能忘记！)
    return 0;
}