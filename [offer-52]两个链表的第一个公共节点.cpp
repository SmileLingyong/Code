/**
 * Creation         :       2019.03.11 00:58
 * Last Reversion   :       2019.03.11 10:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FindFirstCommonNode(两个链表的第一个公共节点)
 * 题目描述
 *      输入两个链表，找出它们的第一个公共结点。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

/**
 * 尾插法创建单链表: 返回不带头节点的单链表
 * (使用带头节点的单链表，然后返回头节点的next）
 */
ListNode* ListCreate3(ListNode*& L) {
    ListNode *s, *r;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    r = L;  // r为表尾指针
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s;
        r = s;  // 指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;  // 尾节点指针置空
    L = L->next;
    return L;
}

/**
 * 打印输出单链表，不带头结点的单链表
 */
void ListPrint(ListNode*& L) {
    ListNode* p = L;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

/**
 * 先计算连个链表的长度，然后计算两个链表差多少lenDif，让长的链表先走lenDif，然后短的链表再开始出发，
 * 然后当他们第一次相遇的时候，就是他们的第一个公共节点了。
 */ 
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int len1 = 0, len2 = 0, lenDif, i;
    ListNode *p, *pLong, *pShort;

    // 计算两个链表的长度
    p = pHead1;
    while (p != NULL) {
        len1++;
        p = p->next;
    }
    p = pHead2;
    while(p != NULL){
        len2++;
        p = p->next;
    }

    // 记录长的链表短的链表分别是谁，以及他们相差多少
    lenDif = len1 - len2;
    pLong = pHead1;
    pShort = pHead2;
    if(lenDif < 0) {
        pLong = pHead2;
        pShort = pHead1;
        lenDif = -lenDif;
    }

    // 让长的链表先走lenDif个长度，然后短的链表再开始走
    for (i = 0; i < lenDif; i++) {
        pLong = pLong->next;
    }
    while(pLong != NULL && pLong->val != pShort->val) {
        pLong = pLong->next;
        pShort = pShort->next;
    }
    return pLong;
}

int main() {
    ListNode *A, *B;
    ListCreate3(A);
    ListPrint(A);
    ListCreate3(B);
    ListPrint(B);

    printf("The first common node is %d\n", FindFirstCommonNode(A, B)->val);
    return 0;
}