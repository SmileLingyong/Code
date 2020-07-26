/**
 * Creation         :       2019.05.12 16:52
 * Last Reversion   :       2019.05.12 16:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
rotateRight(旋转链表) 
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
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
 * 方法一：使用快慢指针，快指针先走k步，然后两个指针一起走，当快指针到末尾时，
 * 慢指针的下一个位置是新的顺序的头结点，这样就可以旋转链表了。但再这之前需要处理
 * 一下k，可能k的值远远大于链表的长度，我们需要首先遍历一下链表，得到链表的长度len，
 * 然后，用 k %= len，这样 k 肯定小于链表长度了，就可以按照上面的方法了。
 */ 
ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;
    int n = 0;
    ListNode *cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }
    k %= n;
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < k; ++i) {
        if (fast)  fast = fast->next;
    }
    if (!fast) return head;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    fast = slow->next;
    slow->next = NULL;
    return fast;
}

/**
 * 方法二：和上面方法类似，不用快慢指针，只用一个指针，原理是先遍历整个链表获得链表
 * 长度n，然后此时把链表头和尾链接起来，在往后走n - k % n个节点就到达新链表的头结点
 * 前一个点，这时断开链表即可。
 */ 
ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int stride = n - k % n;
    for (int i = 0; i < stride; ++i) {
        cur = cur->next;
    }
    ListNode *new_head = cur->next;
    cur->next = NULL;
    return new_head;
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
    int k;
    cout << "请输入链表每个节点需要向右移动的k个位置:";
    cin >> k;
    L = rotateRight(L, k);
    printLinkList(L);
    return 0;
}