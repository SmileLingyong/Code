/**
 * Creation         :       2019.05.12 15:13
 * Last Reversion   :       2019.05.12 15:13
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
partition(分隔链表) 
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。

示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
 * -----------------------------------------------------------------
 * Crop cur @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <stack>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL) {}
}ListNode;

/**
 * 方法一：首先找到第一个大于或等于给定值的节点，用题目中给的例子来说就是先找到4，
 * 然后再找小于3的值，每找到一个就将其取出置于4之前即可.
 * （其中的交换链表节点是很常用的方法）
 */ 
ListNode* partition(ListNode* head, int x) {
    ListNode *header = new ListNode(-1);
    header->next = head;
    ListNode *pre = header, *cur = head;
    while (pre->next && pre->next->val < x) {
        pre = pre->next;
    } 
    cur = pre;
    while (cur->next) {
        if (cur->next->val < x) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return header->next;
}

/**
 * 方法二：将所有小于给定值的节点取出，组成一个新的链表，此时原链表中
 * 剩余的节点的值都大于或等于给定值，只要将只要将原链表直接接在新链表后即可
 */
ListNode* partition(ListNode* head, int x) {
    if (head == NULL) return head;
    ListNode *header_A = new ListNode(-1);
    ListNode *header_B = new ListNode(-1);
    header_A->next = head;
    ListNode *cur = header_A, *p = header_B;
    while (cur->next) {
        if (cur->next->val < x) {
            p->next = cur->next;
            p = p->next;
            cur->next = cur->next->next;
            p->next = NULL;
        } else {
            cur = cur->next;
        }
    }
    p->next = header_A->next;
    return header_B->next;
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
    int x;
    cout << "请输入x:";
    cin >> x;
    L = partition(L, x);
    printLinkList(L);
    return 0;
}