/**
 * Creation         :       2019.03.10 20:05
 * Last Reversion   :       2019.03.10 20:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
Merge(和并两个排序的链表)
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>


typedef struct ListNode {
	int val;
	struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

/**
 * 尾插法创建单链表：注意这里使用的是不带头结点的单链表
 * （也可以使用带头节点的单链表，然后返回头节点的next即可）
 */ 
ListNode* ListCreate2(ListNode* &L) {
    ListNode *s, *p;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    p = L;
    scanf("%d", &x);
    if (x != 999) {
        L->val = x;
        L->next = NULL;
    }
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        p->next = s;          // 指向新的表尾节点
        p = s;          
        scanf("%d", &x);
    }
    p->next = NULL;
    return L;
}

/**
 * 尾插法创建单链表: 返回不带头节点的单链表
 * (使用带头节点的单链表，然后返回头节点的next）
 */ 
ListNode* ListCreate3(ListNode* &L) {
    ListNode *s, *r;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    r = L;              // r为表尾指针
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s;    
        r = s;          // 指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;     // 尾节点指针置空
    return L->next;
}

/**
 * 打印输出单链表，不带头结点的单链表
 */ 
void ListPrint(ListNode* &L) {
    ListNode *p = L;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

/**
 * 方法一：简单高效版本
 */ 
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode *C = new ListNode(-1), *p = C;
    while (pHead1 && pHead2) {
        if (pHead1->val < pHead2->val) {
            p->next = pHead1;
            pHead1 = pHead1->next;  
        } else {
            p->next = pHead2;
            pHead2 = pHead2->next;
        }
        p = p->next;
    }
    if (pHead1) p->next = pHead1;
    if (pHead2) p->next = pHead2;
    return C->next;
}

/**
 * 方法二：自己的写法，太冗余了
 * 合并两个升序的链表(迭代方法)
 */ 
ListNode* MergeII(ListNode* pHead1, ListNode* pHead2) {
    ListNode *C, *s, *p;
    C = (ListNode*)malloc(sizeof(ListNode));
    C->next = NULL;
    p = C;
    while(pHead1 != NULL && pHead2 != NULL) {
        s = (ListNode*)malloc(sizeof(ListNode));
        if (pHead1->val <= pHead2->val) {
            s->val = pHead1->val;
            pHead1 = pHead1->next;
        } else {
            s->val = pHead2->val;
            pHead2 = pHead2->next;
        }
        p->next = s;
        p = s;
    }
    while (pHead1 != NULL) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = pHead1->val;
        p->next = s;
        p = s;
        pHead1 = pHead1->next;
    }
    while (pHead2 != NULL) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = pHead2->val;
        p->next = s;
        p = s;
        pHead2 = pHead2->next;
    }
    p->next = NULL;
    return C->next;
}

/**
 * 合并两个升序的链表(递归方法)
 * (不熟悉，多看几遍)
 */ 
ListNode* MergeIII(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL)
        return pHead2;
    if (pHead2 == NULL)
        return pHead1;
    ListNode *pMerge = NULL;
    if (pHead1->val <= pHead2->val) {
        pMerge = pHead1;
        pMerge->next = Merge(pHead1->next, pHead2);
    } else {
        pMerge = pHead2;
        pMerge->next = Merge(pHead1, pHead2->next);
    }
    return pMerge;
}

int main() {
    ListNode *A, *B, *C;
    ListCreate2(A);
    ListPrint(A);
    ListCreate2(B);
    ListPrint(B);
    C = Merge(A, B);
    ListPrint(C);
    return 0;
}