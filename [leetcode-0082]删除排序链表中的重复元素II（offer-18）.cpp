/**
 * Creation         :       2019.05.11 16:29
 * Last Reversion   :       2019.05.11 16:29
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * deleteDuplicatesII(删除排序链表中的重复元素 II) [剑指offer18变种]
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
 * -----------------------------------------------------------------
 * Crop last @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

/**
 * 方法一：使用三个指针
 */ 
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head; 
    ListNode *pre = NULL, *cur = head, *last = head->next;
    while (last) {
        if (cur->val == last->val) {        // 当cur和last相等时，则一直找是否有连续的下一个last和cur相等
            while (last && cur->val == last->val) {
                last = last->next; 
            }
            if (pre == NULL) {              // （处理特殊情况）若父节点为NULL，则说明第一个节点和第二个节点相等，直接将head指向last即可，自己画个图就明白
                head = last;                // 此时cur也指向last
                cur = last;
            } else {                        // 若pre不为NULL，则说明最开始的两个节点不相等，pre往后移动过，则用pre->next指向last，cur也指向last
                pre->next = last;
                cur = last;
            }
            if (last != NULL) {             // 处理last指针，若last指针已经是NULL，就不用指向下一个了，自己会结束循环。否则，则将last后移。
                last = last->next;
            }
        } else {                            // cur->val 和 last->val 不相等的情况，都往后移
            pre = cur;
            cur = last;
            last = last->next;
        }
    }
    return head;
}

/**
 * 方法二：增加一个头节点(代码更精简！)
 */
ListNode* deleteDuplicatesII(ListNode* head) {
    if (head == NULL || head->next == NULL) 
        return head;
    ListNode *head_pre = new ListNode(-1);
    head_pre->next = head;
    ListNode *pre = head_pre, *cur = head, *last = NULL;
    while (cur && cur->next) {
        last = cur->next;
        if (cur->val == last->val) {
            while (last && cur->val == last->val) {
                last = last->next;
            }
            pre->next = last;
            cur = last;
        } else {
            pre = cur;
            cur = last;
        }
    } 
    return head_pre->next;
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
    L = deleteDuplicatesII(L);
    printLinkList(L);
    return 0;
}