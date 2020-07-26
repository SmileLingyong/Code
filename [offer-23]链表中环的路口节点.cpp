/**
 * Creation         :       2019.03.10 15:16
 * Last Reversion   :       2019.03.10 16:55
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
EntryNodeOfLoop(链表中环的路口节点)
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

/**
 * 链表中环的入口：
 *    先确定一个链表中包含环，然后再计算环的长度，然后就可以按照[offer-23]思想，找到环的入口。
 * 我们通过用两个指针，一个指针slow步长为１，一个指针fast步长为2，这样如果存在环的话，肯定会相遇。
 * 当相遇的时候fast走了2x个节点，slow走了x个节点，fast比slow多走了一个环n，即2x = x + n, 即　x = n; 
 * 然后就可以按照[offer-23]的思想找环的路口，先让一个走ｎ个节点，然后第二个再开始走，他们相遇时的节点就是环的路口节点。
 *                  ____________________
 *                 |                    |
 *                 V                    |
 *  [1]--->[2]--->[3]--->[4]--->[5]--->[6]
 */ 

/**
 * 方法一：使用快慢指针
 */ 
ListNode* EntryNodeOfLoop(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    } 
    if (!fast || !fast->next) return NULL;  // 遍历到了NULL，说明不存在环
    // 当fast 和 slow相遇时，此时fast已近比slow多走了 x = n即环的长度，
    // 此时slow再从head开始走，当fast和slow相遇时，即是环的入口，即倒数第n个节点
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * 判断一个链表是否有环：使用快慢指针
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