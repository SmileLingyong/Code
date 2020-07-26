/**
 * Creation         :       2019.03.09 12:14
 * Last Reversion   :       2019.03.09
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 链表知识点
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

/**
 * 定义单链表节点
 */
typedef struct LNode {
    int data;            // data中存放节点数据域（默认是int型）
    struct LNode *next;  // 指向后继节点的指针
} LNode, *LinkList;      // 定义单链表节点类型

/**
 * 定义双链表节点
 */
typedef struct DLNode {
    int data;              // data中存放节点数据域（默认是int型）
    struct DLNode *prior;  // 指向前驱节点的指针
    struct DLNode *next;   // 指向后继节点的指针
} DLNode;                  // 定义双链表节点类型

/**
 * 头插法创建单链表
 */ 
LinkList ListCreate1(LinkList &L) {
    LNode *s;   
    int x;
    L = (LinkList)malloc(sizeof(LNode));    // 创建头节点
    L->next = NULL;                         // 初始为空链表
    scanf("%d", &x);                        
    while (x != 9999) {                     // 输入节点的值，并动态创建节点，当输入为9999停止输入
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;      // 将新节点插入表中，L为头指针
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 尾插法创建单链表
 */ 
LinkList ListCreate2(LinkList &L) {
    LNode *s, *r;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;              // r为表尾指针
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;    
        r = s;          // 指向新的表尾节点
        scanf("%d", &x);
    }
    r->next = NULL;     // 尾节点指针置空
    return L;
}

/**
 * 打印输出单链表
 */ 
void ListPrint(LinkList &L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 按序号i查找节点的值
 */
LNode* ListGetElem(LinkList &L, int i) {
    int j = 1;      // 计数，初始为1
    LNode *p = L->next;     // 头节点指针赋给p
    if (i == 0)     // 若i为0，返回头结点
        return L;
    if (i < 1)      // 若i无效，则返回NULL
        return NULL;
    while (p != NULL && j != i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找节点x
 */
LNode* ListLocateElem(LinkList &L, int x) {
    LNode *p = L->next;
    while (p != NULL && p->data != x) 
        p = p->next;
    return p;
} 

/**
 * 在i的位置后插入节点x（尾插法）
 */ 
void ListInsertAfter(LinkList &L, int i, int x) {
    LNode* p = ListGetElem(L, i-1);
    LNode* s = (LNode*)malloc(sizeof(LNode));   // 动态创建一个新的节点，存放插入的节点
    s->data = x;
    s->next = p->next;
    p->next = s;
}

/**
 * 在i的位置前插入节点x（前插法）
 * 找到第i-1个位置前的节点即可
 */ 
void ListInsertBefore1(LinkList &L, int i, int x) {
    LNode* p = ListGetElem(L, i-2);
    LNode* s = (LNode*)malloc(sizeof(LNode));   // 动态创建一个新的节点，存放插入的节点
    s->data = x;
    s->next = p->next;
    p->next = s;
}

/**
 * 在i的位置前插入节点x（前插法）
 * 技巧：插入到p后面，但是与插入的节点交换data值，达到前插的效果
 */ 
void ListInsertBefore2(LinkList &L, int i, int x) {
    LNode* p = ListGetElem(L, i-1);
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = x;
    s->data = temp;
}

/**
 * 删除第i个节点
 */ 
void ListDelete(LinkList &L, int i) {
    LNode* p = ListGetElem(L, i-1);
    LNode* q = p->next;
    p->next = q->next;
    free(q);
}

/**
 * 求表长
 */ 
int ListLength(LinkList &L) {
    LNode* p = L->next;
    int len = 0;
    while(p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

int main() {
    int i, x, len;
    /* 创建单链表 */
    printf("Please input the elements of the Linklist, using 9999 end: \n");
    LinkList L = NULL;
    // ListCreate1(L);     // 头插法，插入结果逆序
    ListCreate2(L);        // 尾插法
    ListPrint(L);

    /* 按序号查找节点值 */
    printf("Please input the i position num you want to find: \n");
    scanf("%d", &i);
    LNode* res = ListGetElem(L, i);
    if (res != NULL)
        printf("The %d position num is %d.\n", i, res->data);
    else
        printf("Don't exist i position num.\n");
 
    /* 按值查找 */
    printf("Please input the num you want to search: \n");
    scanf("%d", &x);
    res = ListLocateElem(L, x);
    if (res != NULL)
        printf("The %d is in the LinkList.\n", res->data);
    else
        printf("Don't exist %d num.\n", x);

    /* 插入节点（尾插法） */
    printf("Please input the pos and element you want to insert after(pos, elem): \n");
    scanf("%d %d", &i, &x);
    ListInsertAfter(L, i, x);
    printf("The insert result is :\n");
    ListPrint(L);

    /* 插入节点（前插法） */
    printf("Please input the pos and element you want to insert before(pos, elem): \n");
    scanf("%d %d", &i, &x);
    ListInsertBefore1(L, i, x);
    printf("The insert result is :\n");
    ListPrint(L);   

    /* 删除节点 */ 
    printf("Please input the pos element you want to delete.\n");
    scanf("%d", &i);
    ListDelete(L, i);
    ListPrint(L);

    /* 求单链表长度 */
    len = ListLength(L);
    printf("The Linklist length is %d\n", len);

    return 0;
}
