/**
 * Creation         :       2019.05.11 15:59
 * Last Reversion   :       2019.05.11 15:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * deleteDuplicates(删除排序链表中的重复元素) [剑指offer18]
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
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
 * 方法一：使用一个指针，简洁明了
 */ 
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

/**
 * 方法二：递归方法
 * 首先我们判断是否至少有两个结点，若不是的话，直接返回head。否则对head->next调用递归函数，
 * 并赋值给head->next。这里可能比较晕，我们先看后面一句，返回的时候，head结点先跟其身后的
 * 结点进行比较，如果值相同，那么返回后面的一个结点，当前的head结点就被跳过了，而如果不同的
 * 话，还是返回head结点。我们发现了，进行实质上的删除操作是在最后一句进行了，再来看第二句，
 * 我们对head后面的结点调用递归函数，那么就应该suppose返回来的链表就已经没有重复项了，此时
 * 接到head结点后面，再第三句的时候再来检查一下head是否又duplicate了，实际上递归一直走到了
 * 末尾结点，再不断的回溯回来，进行删除重复结点，
 */ 
ListNode* deleteDuplicatesII(ListNode* head) {
    if (!head || !head->next) return head;
    head->next = deleteDuplicates(head->next);
    return (head->val == head->next->val) ? head->next : head;
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
    L = deleteDuplicates(L);
    printLinkList(L);
    return 0;
}