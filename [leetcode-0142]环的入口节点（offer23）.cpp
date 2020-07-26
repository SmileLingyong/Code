/**
 * Creation         :       2019.05.12 21:00
 * Last Reversion   :       2019.05.12 21:05
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * detectCycle(环的入口节点) [offer23]
 * 题目描述
 *      给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
 * 方法一：使用快慢指针
 */ 
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    } 
    if (!fast || !fast->next) return NULL;  // 遍历到了NULL，说明不存在环
    // 当fast 和 slow相遇时，此时fast已近比slow多走了 x = n即环的长度，此时slow再从head开始走，当fast和slow相遇时，即是环的入口，即倒数第n个节点
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
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