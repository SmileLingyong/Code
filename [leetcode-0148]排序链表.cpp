/**
 * Creation         :       2019.08.26 15:03
 * Last Reversion   :       2019.08.22 15:01
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4

示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode* sortList(ListNode* head) {
    
}

int main() {
    
    return 0;
}