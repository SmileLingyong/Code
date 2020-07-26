/**
 * Creation         :       2019.03.11 00:05
 * Last Reversion   :       2019.03.11 00:58
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DeleteDuplication(删除链表中重复的节点)
 * 题目描述
 *      在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
 * 返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

/**
 * 头插法创建单链表：返回不太头结点的单链表（输入回车结束）
 * 【这里使用的C++方式创建单链表】
 */ 
ListNode *ListCreateHead(ListNode *L) {
    ListNode *s;
    int x;
    L = new ListNode(-1);
    cin >> x;
    while (true) {
        s = new ListNode(x);
        s->next = L->next;
        L->next = s;
        if (getchar() == '\n')
            break;
        cin >> x;
    }
    return L->next;
}

/**
 * 尾插法创建单链表: 返回不带头节点的单链表（输入9999结束）
 * (使用带头节点的单链表，然后返回头节点的next）
 * 【这里使用的是C语言方式创建单链表】
 */
ListNode* ListCreateTail(ListNode*& L) {
    ListNode *s, *r;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    r = L;              // r为表尾指针
    cin >> x;
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s;
        r = s;          // 指向新的表尾节点
        cin >> x;
    }
    r->next = NULL;     // 尾节点指针置空
    L = L->next;
    return L;
}

/**
 * 打印输出单链表，不带头结点的单链表
 */
void ListPrint(ListNode*& L) {
    ListNode* p = L;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


/**
 * 方法一：增加一个头节点，然后使用三指针
 */ 
ListNode* deleteDuplication(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *header = new ListNode(-1);
    header->next = head;
    ListNode *pre = header, *cur = head, *last = NULL;
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
    return header->next;
}


/**
 * 方法二：递归方法，要好好理解一下（没看太明白）
 */ 
ListNode* deleteDuplication2(ListNode* head) {
    if (head == NULL) 
        return NULL;
    if (head != NULL && head->next == NULL) 
        return head;

    ListNode* current;

    if (head->next->val == head->val) {
        current = head->next->next;
        while (current != NULL && current->val == head->val)
            current = current->next;
        return deleteDuplication(current);
    } else {
        current = head->next;
        head->next = deleteDuplication(current);
        return head;
    }
}

int main() {
    ListNode* L;
    L = ListCreateTail(L);  // 尾插法创建单链表，输入9999结束
    // L = ListCreateHead(L);  // 头插法创建单链表，输入回车结束
    ListPrint(L);
    L = deleteDuplication(L);
    ListPrint(L);
    return 0;
}