/**
 * Creation         :       2019.03.10 13:30
 * Last Reversion   :       2019.03.10 13:57
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 队列知识点
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#define MAX_SIZE 100

typedef struct Queue {
    int data[MAX_SIZE];
    int front;  // 存放队列头指针
    int rear;   // 存放队列尾指针
} Queue;

/**
 * 初始化队列
 */
void InitQueue(Queue &q) { 
    q.front = q.rear = 0; 
}

/**
 * 判断队列是否为空
 */
bool IsEmpty(Queue &q) {
    if (q.front == q.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 */
bool EnQueue(Queue &q, int x) {
    if ((q.rear + 1) % MAX_SIZE == q.front) 
        return false;
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % MAX_SIZE;
    return true;
}

/**
 * 出队
 */ 
bool DeQueue(Queue &q, int &x) {
    if (q.front == q.rear)
        return false;
    x = q.data[q.front];
    q.front = (q.front + 1) % MAX_SIZE;
    return true;
}

int main() {
    Queue q;
    int x;
    InitQueue(q);
    EnQueue(q, 1);
    EnQueue(q, 3);
    EnQueue(q, 5);
    DeQueue(q, x);
    printf("%d\n", x);
    return 0;
}
