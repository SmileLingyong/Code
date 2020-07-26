/**
 * Creation         :       2019.05.12 11:23
 * Last Reversion   :       2019.05.12 11:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
swapPairs(两两交换链表中的节点) 
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
 * -----------------------------------------------------------------
 * Crop last @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL) {}
}ListNode;

/**
 * 方法一：自己画图理解一下，比较容易弄糊涂，一定要画图
 */ 
ListNode* swapPairs(ListNode* head) {
    ListNode *header = new ListNode(-1), *pre = header;
    header->next = head;
    while (pre->next && pre->next->next) {
        ListNode *last = pre->next->next;
        pre->next->next = last->next;
        last->next = pre->next;
        pre->next = last;
        pre = last->next;   
    }
    return header->next;
}

/**
 * 多使用了一个指针表示，更容易理解
 */ 
ListNode *swapPair(ListNode *head) {
    ListNode *header = new ListNode(-1), *pre = header;
    header->next = head;
    while (pre->next && pre->next->next) {
        ListNode *cur = pre->next;
        ListNode *last = cur->next;
        cur->next = last->next;
        last->next = pre->next;
        pre->next = last;
        pre = cur;      // 或者 pre = cur
    }
    return header->next;
}


/**
 * 方法二：递归写法，回溯思想(递归的很不熟悉)
 */ 
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *last = head->next;
    head->next = swapPairs(head->next->next);
    last->next = head;
    return last;
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
    L = swapPairs(L);
    printLinkList(L);
    return 0;
}