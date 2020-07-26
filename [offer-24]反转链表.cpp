/**
 * Creation         :       2019.03.10 15:16
 * Last Reversion   :       2019.03.10 16:55
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * ReverseList(反转链表)
 * 题目描述
 *      输入一个链表，反转链表后，输出新链表的表头。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode *next;
    ListNode (int x): val(x), next(NULL) {};
}ListNode;

/**
 * 方法一： 使用尾插法
 * 尾插法创建单链表：注意这里使用的是不带头结点的单链表
 * （也可以使用带头节点的单链表，然后返回头节点的next即可）
 */ 
ListNode* ListCreate2(ListNode* &L) {
    ListNode *s, *r;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    r = L;
    scanf("%d", &x);
    if (x != 999) {
        L->val = x;
        L->next = NULL;
    }
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s;          // 指向新的表尾节点
        r = s;          
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
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
 * 方法二：使用栈的思想
 */ 
ListNode* ReverseList(ListNode* pHead) {
    struct ListNode *p = pHead;
    if (p == NULL)
        return NULL;
    stack<int> s;
    while (p != NULL) {
        s.push(p->val);
        p = p->next;
    }
    p = pHead;
    while (!s.empty()) {
        p->val = s.top();
        s.pop();
        p = p->next;
    }
    return pHead;
}

/**
 * 方法三：指针翻转即可
 * 因为如果把第i个节点的指针指向前一个节点，则i的下一个节点j则会丢之，没有指针指向它了。
 * 为此，我们遍历的时候，需要3个指针，分别指向当前节点，上一节点，和下一节点。并且要细心处理下一节点
 */ 
ListNode* ReverseList2(ListNode* pHead) {
    ListNode *pReverse = NULL;  // 反转后返回的头指针
    ListNode *pNow = pHead;     // 遍历的当前节点
    ListNode *pPre = NULL;      // 上一节点
    ListNode *pNext = NULL;     // 下一节点
    while (pNow != NULL) {      // 如果当前节点不为空，即没有遍历到尾节点后的NULL
        pNext = pNow->next;     // 获取下一节点的指针
        if (pNext == NULL)      // 如果下一节点为空了，则说明已当前节点是最后一个节点，返回
            pReverse = pNow;
        pNow->next = pPre;      // 当前节点指针翻转
        pPre = pNow;            // 遍历下一节点
        pNow = pNext;
    }
    return pReverse;
}

int main() {
    ListNode *L;
    ListCreate2(L);
    ListPrint(L);
    struct ListNode *p;
    p = ReverseList2(L);
    ListPrint(p);

    return 0;
}

