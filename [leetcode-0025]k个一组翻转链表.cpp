/**
 * Creation         :       2019.05.12 15:13
 * Last Reversion   :       2019.05.12 15:13
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * reverseKGroup(k个一组翻转链表) 
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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

ListNode *reverseOneGrop(ListNode *pre, ListNode *end);
ListNode* reverseKGroup(ListNode *head, int k);

/**
 * 方法一：
 * 这道题让我们以每k个为一组来翻转链表，实际上是把原链表分成若干小段，
 * 然后分别对其进行翻转，那么肯定总共需要两个函数，一个是用来分段的，
 * 一个是用来翻转的，我们就以题目中给的例子来看，对于给定链表1->2->3->4->5，
 * 一般在处理链表问题时，我们大多时候都会在开头再加一个header node，因为翻转
 * 链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的header node，
 * 那么我们加入header node后的链表变为-1->1->2->3->4->5，如果k为3的话，
 * 我们的目标是将1,2,3翻转一下，那么我们需要一些指针，pre和last分别指向要翻
 * 转的链表的前后的位置，然后翻转后pre的位置更新到如下新的位置：

    -1->1->2->3->4->5
     |        |  |
     pre     cur last

    -1->3->2->1->4->5
        |     |  |
       cur   pre last

 * 以此类推，只要cur走过k个节点，那么last就是cur->next，就可以调用翻转函数来
 * 进行局部翻转了，注意翻转之后新的cur和pre的位置都不同了，那么翻转之后，cur应
 * 该更新为pre->next，而如果不需要翻转的话，cur更新为cur->next
 */ 
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    ListNode *header = new ListNode(-1), *pre = header, *cur = head;
    header->next = head;
    for (int i = 1; cur; ++i) {
        if (i % k == 0) {
            pre = reverseOneGrop(pre, cur->next);
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }
    return header->next;
}

/**
 * 将该组链表翻转，并返回翻转后的该组头结点3，即翻转前的改组尾节点3
   传入函数前：
        -1 -> 1 -> 2 -> 3 -> 4 -> 5
         |              |    |
        pre           cur  last
    传入函数后，我们将对应的该组进行反转，即设定如下几个指针
        -1 -> 1 -> 2 -> 3 -> 4 -> 5
         |    |    |         |
        pre cur  last      end
    反转一次后：
        -1 -> 2 -> 1 -> 3 -> 4 -> 5
         |         |    |    |
        pre      cur last   end
    last没有指向end，该组没有反转完，继续反转
        -1 -> 2 -> 1 -> 3 -> 4 -> 5
         |              |    |   
        pre            cur  last(end)   
    该组反转完成，返回下一次的前驱节点cur
 */ 
ListNode *reverseOneGrop(ListNode *pre, ListNode *end) {
    ListNode *cur = pre->next, *last = cur->next;
    while (last != end) {           // 画个图，一下就明白了
        cur->next = last->next;
        last->next = pre->next;
        pre->next = last;
        last = cur->next;
    }
    return cur;     // 返回下一组的pre先驱节点
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
    int n;
    cout << "请输入需要按多少组进行翻转：";
    cin >> n;
    L = reverseKGroup(L, n);
    printLinkList(L);
    return 0;
}