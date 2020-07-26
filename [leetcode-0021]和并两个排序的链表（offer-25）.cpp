/**
 * Creation         :       2019.03.10 20:05
 * Last Reversion   :       2019.05.11 10:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Merge(和并两个排序的链表) 结合 [offer-25]
 * 题目描述
 *      输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

/**
 * 方法一：迭代法
 */ 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *C, *s, *r;
    C = new ListNode(-1);
    r = C;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            s = new ListNode(l1->val);
            r->next = s;
            r = s;
            l1 = l1->next;
        } else {
            s = new ListNode(l2->val);
            r->next = s;
            r = s;
            l2 = l2->next;
        }
    }
    while (l1) {
        s = new ListNode(l1->val);
        r->next = s;
        r = s;
        l1 = l1->next;
    }
    while (l2) {
        s = new ListNode(l2->val);
        r->next = s;
        r = s;
        l2 = l2->next;
    }
    return C->next;
}

/**
 * 方法一：迭代版（精简）
 */ 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *C = new ListNode(-1);
    ListNode *p = C;
    while (l1  && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1) p->next = l1;
    if (l2) p->next = l2;
    return C->next;
}


/**
 * 方法二：递归方法
 */ 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;  // 注意这里的返回
    if (l2 == NULL) return l1;
    ListNode *C = NULL;
    if (l1->val <= l2->val) {
        C = l1;
        C->next = mergeTwoLists(l1->next, l2);
    } else {
        C = l2;
        C->next = mergeTwoLists(l1, l2->next);
    }
    return C;
}



int main() {

    return 0;
}

