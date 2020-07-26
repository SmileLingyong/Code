/**
 * Creation         :       2019.05.12 15:13
 * Last Reversion   :       2019.05.12 15:13
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * mergeKLists(合并K个排序链表) 
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
 * -----------------------------------------------------------------
 * Crop cur @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL) {}
}ListNode;

/**
 * 方法一：两两两两合并，超时
 */ 

/**
 * 方法二：采用分治思想
 * 简单来说就是不停的对半划分，比如k个链表先划分为合并两个k/2个链表的任务，
 * 再不停的往下划分，直到划分成只有一个或两个链表的任务，开始合并。举个例子
 * 来说比如合并6个链表，那么按照分治法，我们首先分别合并0和3，1和4，2和5。
 * 这样下一次只需合并3个链表，我们再合并1和3，最后和2合并就可以了。代码中的
 * k是通过 (n+1)/2 计算的，这里为啥要加1呢，这是为了当n为奇数的时候，k能始
 * 终从后半段开始，比如当n=5时，那么此时k=3，则0和3合并，1和4合并，最中间
 * 的2空出来。当n是偶数的时候，加1也不会有影响，比如当n=4时，此时k=2，那么
 * 0和2合并，1和3合并，完美解决问题。
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;
    int n = lists.size();
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        n = k;
    }
    return lists[0];
}

ListNode *mergeTwoLists(ListNode* A, ListNode *B) {
    ListNode *C = new ListNode(-1);
    ListNode *p = C;    // 尾指针，指向链表的最后一个节点
    while (A && B) {
        if (A->val < B->val) {
            p->next = A;
            p = A;
            A = A->next;
        } else {
            p->next = B;
            p = B;
            B = B->next;
        }
    }
    if (A) p->next = A;
    if (B) p->next = B;
    return C->next;
}

/**
 * 方法三：使用最小堆（不熟，要多看几遍）
 * 我们首先把k个链表的首元素都加入最小堆中，它们会自动排好序。然后我们
 * 每次取出最小的那个元素加入我们最终结果的链表中，然后把取出元素的下一
 * 个元素再加入堆中，下次仍从堆中取出最小的元素做相同的操作，以此类推，
 * 直到堆中没有元素了，此时k个链表也合并为了一个链表，返回首节点即可
 */ 
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode*& a, ListNode*& b) {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
    for (auto node : lists) {
        if (node) q.push(node);
    }
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    while (!q.empty()) {
        auto t = q.top(); 
        q.pop();
        cur->next = t;
        cur = cur->next;
        if (cur->next) 
            q.push(cur->next);
    }
    return dummy->next;
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