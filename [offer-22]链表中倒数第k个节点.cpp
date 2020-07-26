/**
 * Creation         :       2019.03.10 16:56
 * Last Reversion   :       2019.03.10 17:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
FindKthToTail(链表中倒数第k个节点)
题目描述
   输入一个链表，输出该链表中倒数第k个结点。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 思路：使用快慢指针
 */ 

ListNode* FindKthToTailII(ListNode* pListHead, unsigned int k) {
    if (!pListHead || k < 1)
        return NULL;
    ListNode *fast = pListHead, *slow = pListHead;

    for (int i = 0; i < k - 1; i++) {
        if (fast->next)
            fast = fast->next;
        else
            return NULL;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}