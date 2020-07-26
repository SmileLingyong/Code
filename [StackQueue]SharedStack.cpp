/**
 * Creation         :       2019.03.10 11:12
 * Last Reversion   :       2019.03.10 11:32
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 共享栈实现 P61 P65
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100

typedef struct SharedStack {
    int data[MAX_SIZE];   // 栈空间
    int top[2];           // 两个栈顶指针
} SharedStack;

/**
 * 入栈操作：i 为栈号，i=0 表示左边的 s1 栈，i=1 表示右边的 s2栈，x是入栈元素
 *         入栈成功返回1，否则返回0
 */
int Push(SharedStack &s, int i, int x) {
    if (i < 0 || i > 1) {
        printf("栈号输入不对！\n");
        exit(0);
    }
    if (s.top[1] - s.top[0] == 1) {
        printf("栈已满！\n");
        return 0;
    }
    switch (i) {
        case 0:
            s.data[++s.top[0]] = x;    // 先+1再左进
            return 1;
            break;
        case 1:
            s.data[--s.top[1]] = x;    // 先-1再右进
            return 1;
            break;
    }
}

/**
 * 出栈操作
 */ 
int Pop(SharedStack &s, int i) {
    if (i < 0 || i > 1) {
        printf("栈号输入不对！\n");
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                printf("栈空!\n");
                return -1;
            } else {
                return s.data[s.top[0]--]; // 先左出栈，再--
            }

        case 1:
            if (s.top[1] == MAX_SIZE) {
                printf("栈空!\n");
                return -1;
            } else {
                return s.data[s.top[1]++]; // 先右出栈，再++
            }
    }
}

/**
 * 初始化栈
 */ 
void InitStack(SharedStack &s) {
    s.top[0] = -1;
    s.top[1] = MAX_SIZE;
}

int main() { 
    SharedStack s;  // 创建一个共享栈
    InitStack(s);
    Push(s, 0, 1);
    Push(s, 0, 5);
    Push(s, 1, 3);
    printf("%d\n", Pop(s, 0));
    printf("%d\n", Pop(s, 1));
    printf("%d\n", Pop(s, 1));
    return 0; 
}
