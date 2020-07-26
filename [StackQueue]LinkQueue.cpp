/**
 * Creation         :       2019.03.10 13:30
 * Last Reversion   :       2019.03.10 13:57
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 链式队列
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

/**
 * 链式队列节点
 */ 
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode; 

/**
 * 链式队列
 */ 
typedef struct LinkQueue{
    LNode *front, *rear;
}LinkQueue;

/**
 * 初始化链队列
 */ 
void InitQueue(LinkQueue &q) {
    q.front = q.rear = (LNode*)malloc(sizeof(LNode)); // 建立头节点
    q.front->next = NULL;      // 初始为空
}

/**
 * 判断队空
 */ 
bool IsEmpty(LinkQueue &q) {
    if (q.front == q.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 */ 
void EnQueue(LinkQueue &q, int x) {
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;     // 创建新节点，插入到链尾
    q.rear->next = s;
    q.rear = s;
}

/**
 * 出队
 */ 
bool DeQueue(LinkQueue &q, int &x) {
    if (q.front == q.rear) return false;    // 队列为空
    LNode *p = q.front->next;
    x = p->data;
    q.front->next = p->next;
    if (p == q.rear)            // 若原队列总只有一个节点，删除后变为空
        q.front = q.rear;
    free(p);
    return true;
}

int main() {
    int x;
    LinkQueue q;
    InitQueue(q);
    EnQueue(q, 1);
    EnQueue(q, 3);
    DeQueue(q, x);
    printf("%d\n", x);
    DeQueue(q, x);

    return 0;
}