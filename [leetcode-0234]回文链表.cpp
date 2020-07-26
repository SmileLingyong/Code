/**
 * Creation         :       2019.05.12 15:13
 * cur Reversion   :       2019.05.12 15:13
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * isPalindrome(回文链表) 
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
 * 方法一：使用快慢指针以及栈
 *    使用快慢指针找链表的中点。使用fast和slow两个指针，每次快指针走两步，
 * 慢指针走一步，等快指针走完时，慢指针的位置就是中点。我们还需要用栈，每次慢指针
 * 走一步，都把值存入栈中，等到达中点时，链表的前半段都存入栈中了，由于栈的后进先
 * 出的性质，就可以和后半段链表按照回文对应的顺序比较了。
 */ 
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    stack<int> stk;
    ListNode *fast = head, *slow = head;
    stk.push(head->val);
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        stk.push(slow->val);
    }
    if (fast->next == NULL) {   // 即此时链表长为奇数
        stk.pop();  
    }
    slow = slow->next;
    while (!stk.empty()) {
        if (stk.top() == slow->val) {
            slow = slow->next;
            stk.pop();
        } else {
            return false;
        }
    }
    return true;
}

/**
 * 方法二：使用快慢指针，不使用栈
 * 使用快慢指针找到中点后，将后半部分链表翻转，然后对应比较即可
 */ 
bool isPalindromeII(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *cur = slow->next, *pre = head;
    while (cur->next) {
        ListNode *t = cur->next;
        cur->next = t->next;
        t->next = slow->next;
        slow->next = t;
    }
    slow = slow->next;
    while (slow) {
        if (slow->val == pre->val) {
            slow = slow->next;
            pre = pre->next;
        } else {
            return false;
        }
    }
    return true;
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
    if (isPalindromeII(L))
        cout << "True";
    else 
        cout << "False";
    return 0;
}