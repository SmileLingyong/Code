/**
 * Creation         :       2019.03.11 00:58
 * Last Reversion   :       2019.05.12 21:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FindFirstCommonNode(两个链表的第一个公共节点)
 * 题目描述
 *      输入两个链表，找出它们的第一个公共结点。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL) {}
}ListNode;

/**
 * 方法一：先计算连个链表的长度，然后计算两个链表差多少lenDis，让长的链表先走lenDif，然后短的链表再开始出发，
 * 然后当他们第一次相遇的时候，就是他们的第一个公共节点了。
 */ 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0, lenDis;
    ListNode *p, *pLong, *pShort;
    p = headA;
    while (p) {
        lenA++;
        p = p->next;
    }
    p = headB;
    while (p) {
        lenB++;
        p = p->next;
    }
    lenDis = lenA - lenB;
    pLong = headA;
    pShort = headB;
    if (lenDis < 0) {
        pLong = headB;
        pShort = headA;
        lenDis = -lenDis;
    }  
    for (int i = 0; i < lenDis; i++) {
        pLong = pLong->next;
    }
    while (pShort != pLong) {
        pLong = pLong->next;
        pShort = pShort->next;
        if (!pLong || !pShort)  // 有一个遍历到了NULL末尾，则说明他们没有相交节点
            return NULL;
    }
    return pShort;
}

/**
 * 创建单链表：尾插法(返回不带头结点的单链表)
 */ 
ListNode * createLinkList(ListNode *L) {
    L = new ListNode(-1);
    ListNode *r, *s;
    r = L;  // 尾指针，始终指向尾节点
    int n;
    while (cin >> n && n != 9999) {
        s = new ListNode(n);
        r->next = s;
        r = s;
    }
    return L->next;
}

/**
 * 打印单链表
 */ 
void printLinkList(ListNode *L) {
    while (L) {
        cout << L->val << " ";
        L = L->next;
    }
    cout << endl;
}

int main() {
    ListNode *L;
    L = createLinkList(L);
    printLinkList(L);
    return 0;
}