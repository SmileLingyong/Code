/**
 * Creation         :       2019.05.12 16:52
 * Last Reversion   :       2019.05.12 16:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
reverseBetween(反转链表范围) 
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
 * -----------------------------------------------------------------
 * Reference: http://www.cnblogs.com/grandyang/p/4306611.html
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
 * 方法一：常用方法，构建一个头节点
 * 然后，下面的方法很经典，必须要会！！！
 * 首先遍历到m位置的前一个位置，做为我们的pre，
 * cur = pre->next; 建立一个临时节点t，指向cur->next 即t = cur->next;
 * （注意，使用临时变量保存某个节点就是为了首先断开该节点和前面节点之间的联系！！！）
 * 然后不断交换pre之后的节点，这里要画图理解。
 * 比如原始链表如下，m = 2, n = 4，即pre指向 1，cur = 2，t = 3
 * 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * |    |    |
 * pre  cur  t
 * 第一次交换后就是：
 * 1 -> 3 -> 2 -> 4 -> 5 -> NULL
 * |    |    |
 * pre  t   cur
 * 然后继续交换，t = cur->next;
 * 1 -> 3 -> 2 -> 4 -> 5 -> NULL
 * |         |    |
 * pre      cur   t
 * 第二次交换后的结果为：
 * 1 -> 4 -> 3 -> 2 -> 5 -> NULL
 * |    |         |
 * pre  t        cur
 * 完成交换
 */
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *header = new ListNode(-1), *pre = header;
    header->next = head;
    for (int i = 0; i < m - 1; ++i) pre = pre->next;
    ListNode *cur = pre->next;
    for (int i = m; i < n; ++i) {
        ListNode *t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
    }
    return header->next;
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
    int m, n;
    cout << "请输入需要翻转链表的起始和终止下标，m 和 n:";
    cin >> m >> n;
    L = reverseBetween(L, m, n);
    printLinkList(L);
    return 0;
}