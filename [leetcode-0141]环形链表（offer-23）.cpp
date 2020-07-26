/**
 * Creation         :       2019.05.12 21:00
 * Last Reversion   :       2019.05.12 21:05
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * hasCycle(环形链表) [offer23]
 * 给定一个链表，判断链表中是否有环。
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
bool hasCycle(ListNode *head) {
    if (!head || head->next == NULL) return false;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) 
            return true;
    }
    return false;
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
    int m, n;
    cout << "请输入需要翻转链表的起始和终止下标，m 和 n:";
    cin >> m >> n;
    L = reverseBetween(L, m, n);
    printLinkList(L);
    return 0;
}