/**
 * Creation         :       2019.03.10 00:14
 * Last Reversion   :       2019.03.10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * printListFromTailToHead(从尾到头打印链表)
 * 题目描述
 *    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
} ListNode;
    
/**
 * 使用栈的方式，逆序存储单链表
 */ 
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;
    stack<int> s;
    ListNode *p = head;     // 注意，题目默认不含头节点
    while (p != NULL) {
        s.push(p->val);
        p = p->next;
    }
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

/**
 * 创建单链表（头插法）
 */ 
void ListCreate(ListNode* &L) {
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    ListNode* s;
    scanf("%d", &x);
    while (x != 9999) {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}

/**
 * 尾插法
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
    return L;
}

/**
 * 打印单链表
 */ 
void ListPrint(ListNode* &L){
    ListNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {
    ListNode *L;
    ListCreate2(L);
    ListPrint(L);

    vector <int> res = printListFromTailToHead(L);
    printf("The result is :\n");
    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
