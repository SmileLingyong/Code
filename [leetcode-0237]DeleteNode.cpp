/**
 * Creation         :       2019.05.11 17:19
 * Last Reversion   :       2019.05.11 17:19
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DeleteNode(删除链表中的节点)
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

示例 1:

输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], node = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 
【说明】:
链表至少包含两个节点。
链表中所有节点的值都是唯一的。
给定的节点为非末尾节点并且一定是链表中的一个有效节点。
不要从你的函数中返回任何结果。
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
 * 删除一个节点（很经典的方法，要会！）
 * 1 --> 2 --> 3 --> 4
 * 如上，比如要删除节点2，则我们可以将节点2: node->val = 3; 
 * 然后再将其指针指向3的next即可。
 */ 
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

/**
 * 创建单链表：尾插法(返回不带头结点的单链表)
 */ 
ListNode *createLinkList(ListNode *L) {
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

ListNode *getNode(ListNode *L, int x) {
    while (L && L->val != x) {
        L = L->next;
    }
    return L;
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
    ListNode *L, *node;
    L = createLinkList(L);
    printLinkList(L);

    int x;
    cout <<  "请输入要删除的节点：";
    cin >> x;
    node = getNode(L, x);
    deleteNode(node);
    printLinkList(L);
    return 0;
}