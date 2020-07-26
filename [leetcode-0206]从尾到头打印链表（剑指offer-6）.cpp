/**
 * Creation         :       2019.05.11 09:06
 * Last Reversion   :       2019.05.11 10:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
printListFromTailToHead(从尾到头打印链表)
题目描述
   输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
思考：这道题为什么会花一个小时呢，因为编译器的一个Bug，然自己重写了很多遍！
-----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define MAX_SIZE 100

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法一：使用头插法创建节点
 * 超级Bug，leetcode中 C++用C的malloc方式写不能通过！
 * 然后又改成了下面使用new()的方式
 */ 
ListNode* reverseListII(ListNode* head) {
    ListNode *L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    ListNode *s;
    while (head) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = head->val;
        s->next = L->next;
        L->next = s;
        head = head->next;
    }
    return L->next;
}


/**
 * 方法一：使用头插法创建节点
 * 改成使用new()的方式创建链表节点就可以通过了
 */ 
ListNode* reverseListII_CPP(ListNode* head) {
    ListNode *L = new ListNode(-1);
    ListNode *s;
    while (head) {
        s = new ListNode(head->val);
        s->next = L->next;
        L->next = s;
        head = head->next;
    }
    return L->next;
}

/**
 * 方法二: 使用栈存储
 * C++编译器，使用malloc()方式创建节点无法通过
 */ 
ListNode* reverseList(ListNode* head) {
    stack<int> stk;
    while (head) {
        stk.push(head->val);
        head = head->next;
    }
    ListNode *L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    ListNode *r, *s;
    r = L;
    while (!stk.empty()) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = stk.top();
        stk.pop();
        s->next = NULL;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L->next;
}

/**
 * 尾插法创建链表（返回不带头节点的单链表）
 */ 
ListNode* ListCreate2(ListNode* &L) {
    ListNode *s, *r;
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    r = L;              // r为表尾指针
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s;    
        r = s;          // 指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;     // 尾节点指针置空
    return L->next;
}

/**
 * 打印不带头节点的单链表
 */ 
void ListPrint(ListNode *L) {
    while (L) {
        cout << L->val << " ";
        L = L->next;
    }
}

int main() {
    ListNode *L;
    L = ListCreate2(L);
    L = reverseList(L);
    ListPrint(L);
    return 0;
}
