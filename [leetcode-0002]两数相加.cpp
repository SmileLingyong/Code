/**
 * Creation         :       2019.05.09 16:36
 * Last Reversion   :       2019.05.09 16:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
AddTwoNumbers(两数相加)
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *header = new ListNode(-1), *cur = header;
    int carry = 0;
    while (l1 || l2) {
        int val_1 = l1 ? l1->val : 0;
        int val_2 = l2 ? l2->val : 0;
        int sum = val_1 + val_2 + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(1);
    return header->next;
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
    ListNode *l1, *l2;
    l1 = createLinkList(l1);
    l2 = createLinkList(l2);
    printLinkList(addTwoNumbers(l1, l2));
    return 0;
}