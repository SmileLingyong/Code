/**
 * Creation         :       2019.05.11 17:19
 * Last Reversion   :       2019.05.11 17:19
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * RemoveElements(移除链表元素)
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

/**
 * 方法一：增加一个头节点，便于操作
 */ 
ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) return NULL;
    ListNode *hearder = new ListNode(-1);
    hearder->next = head;       // 在头节点之前，增加一个节点，以便操作
    ListNode *cur = hearder;
    while (cur) {
        if (cur->next && cur->next->val == val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return hearder->next;
}


/**
 * 创建单链表：尾插法(返回不带头结点的单链表)
 */ 
ListNode * createLinkList(ListNode *L) {
    L = new ListNode(-1);
    ListNode *r, *s;
    r = L;  // 尾指针，始终指向尾节点
    int x;
    while (cin >> x && x != 9999) {
        s = new ListNode(x);
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
    int x;
    cout <<  "请输入要删除的节点：";
    cin >> x;
    L = removeElements(L, x);
    printLinkList(L);
    return 0;
}