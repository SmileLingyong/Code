/**
 * Creation         :       2019.03.11 10:36
 * Last Reversion   :       2019.03.11 15:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
LinkClone(复杂链表的复制)
题目描述
    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
}RandomListNode;


/**
 * 书上使用的技巧：
 *      第一步，在每个节点的后面插入复制的节点。
 *      第二步，对复制节点的 random 链接进行赋值。
 *      第三步，拆分链表。
 */ 
RandomListNode* Clone(RandomListNode *pHead) {

    if (!pHead)
        return NULL;
    // 首先在每个节点后面插入复制的节点s
    RandomListNode *L = NULL, *p = pHead, *s;
    while (p != NULL) {
        s = (RandomListNode*)malloc(sizeof(RandomListNode));
        s->label = p->label;
        s->next = p->next;
        p->next = s;
        p = s->next;    // 指向下一个节点
    }
    s->next = NULL;
    
    // 对复制节点的random进行赋值
    p = pHead;
    while (p != NULL) {
        s = p->next;
        if (p->random != NULL) {
            s->random = p->random->next;
        } 
        p = s->next;
    }
    
    // 拆分链表:自己画图理解一下
    p = pHead;
    L = p->next;
    while (p->next != NULL) {
        s = p->next;
        p->next = s->next;
        p = s;
    }
    return L;
}

// Todo: 使用Hash表的方法处理
RandomListNode* Clone1(RandomListNode* pHead) {
    
}


