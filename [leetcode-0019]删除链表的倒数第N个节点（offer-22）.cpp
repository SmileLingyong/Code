/**
 * Creation         :       2019.05.12 11:00
 * Last Reversion   :       2019.05.12 11:20
 * fastuthor           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
removeNthFromEnd(删除链表的倒数第N个节点) 
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：
给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？
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
 * 方法一：使用快慢指针，让fast先走(n+1)步，slow再从表头开始走，这样fast走到末尾时，slow刚好走到要删除节点的先驱节点
 * 然后slow->next = slow->next->next就可以删除了
 */ 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    if (fast == NULL) {    // 若删除的是头结点，则fast先走n步之后就到NULL了，此时，直接返回头结点的next节点即可
        return head->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
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
    int n;
    cout <<  "要删除倒数第几个节点：";
    cin >> n;
    L = removeNthFromEnd(L, n);
    printLinkList(L);
    return 0;
}