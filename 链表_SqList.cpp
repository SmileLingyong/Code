/**
 * Creation         :       2019.03.09 12:14
 * Last Reversion   :       2019.03.09
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 顺序表知识点
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#define MAX_SIZE 100

/**
 * 定义顺序表结构体
 */
typedef struct SqList {
    int data[MAX_SIZE];  //存放顺序表元素的数组
    int length;          // 顺序表的长度
} SqList;                // 顺序表类型的定义

/**
 * 定义单链表节点
 */
typedef struct LNode {
    int data;            // data中存放节点数据域（默认是int型）
    struct LNode *next;  // 指向后继节点的指针
} LNode, *LinkList;                 // 定义单链表节点类型

/**
 * 定义双链表节点
 */
typedef struct DLNode {
    int data;              // data中存放节点数据域（默认是int型）
    struct DLNode *prior;  // 指向前驱节点的指针
    struct DLNode *next;   // 指向后继节点的指针
} DLNode;   

/**
 * @brief: 创建顺序表
 * @return: 返回顺序表长度
 */ 
int ListCreate(SqList &L) {
    L.length = 0;
    int x, i = 0;
    scanf("%d", &x);
    while (x != 9999) {
        L.data[i++] = x;
        scanf("%d", &x);
    }
    L.length = i;
    return L.length;
}

/**
 * @brief: 将元素e插入到顺序表L中第i个位置
 */
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)  // 判断i的范围是否有效，注意i从1开始，表示第几个位置
        return false;
    if (L.length >= MAX_SIZE)       // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) {   // 将第i个元素及以后的元素后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;              // 在位置i处放入e
    L.length++;
    return true;
}

/**
 * @brief: 打印输出顺序表
 */  
void ListPrint(SqList &L) {
    for (int i = 0; i < L.length; i++) 
        printf("%d ", L.data[i]);
    printf("\n");
}

/**
 * @brief: 在顺序表中查找第一个为e的元素，并返回其位置
 */ 
int ListLocateElem(SqList &L, int e) {
    for (int i = 0; i < L.length; i++) 
        if (L.data[i] == e)
            return i+1;
    return 0;
}

/**
 * @brief: 删除顺序表L中第i个元素，成功放回true，并将被删除的元素用引用变量e返回，否则返回false
 */
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) 
        return false;
    e = L.data[i - 1];          
    for (int j = i; j < L.length; j++)  // 将第i个位置之后的元素前移
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

/**
 * @brief: 删除顺序表中所有的x元素
 */ 
void ListDeleteAllX(SqList &L, int x) {
    int i, k = 0;      // 记录不等于k的元素个数
    for (i = 0; i < L.length; i++) {
        if (L.data[i] != x){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

void ListDeleteAllX1(SqList &L, int x) {
    int i, k = 0;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == x)
            k++;
        else 
            L.data[i-k] = L.data[i];
    L.length -= k;
}

/**
 * @brief: 删除顺序表中值在s和t的所有元素
 */ 
void ListDeleteALLST(SqList &L, int s, int t) {
    int i, k = 0;
    for (i = 0; i < L.length; i++)
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i-k] = L.data[i];
    L.length -= k;
}

/**
 * @brief: 删除有序顺序表中所有重复元素
 */ 
void ListDeleteOrderListRepeatElem(SqList &L) {
    int i, j;       // i存储第一个不相同的元素，j工作指针
    for (i = 0, j = 1; j < L.length; j++) 
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    L.length = i;
}

/**
 * @brief: 将顺序表翻转
 */ 
void ListReverse(SqList &L) {
    int i, j, temp;
    for (i = 0, j = L.length - 1; i < j; i++, j--) {
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
    }
}

/**
 * @brief: 合并有序顺序表成一个新的有序表
 */ 
bool ListMerge(SqList &A, SqList &B, SqList &C) {
    if (A.length + B.length > MAX_SIZE)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length) 
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

/**
 * @brief: 线性表L中元素递增且有序，用最少的时间复杂度查找元素x，若找到将其与后继元素位置交换，做找不到则将其插入表中，使其任有序
 *         使用二分查找的思想。
 */ 
void ListSearchExchangeInsert(SqList &L, int x) {
    int low = 0, high = L.length, mid, temp, i;
    while (low <= high) {
        mid = (mid + high) / 2;
        if (L.data[mid] == x)   
            break;
        else if (L.data[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (L.data[mid] == x && mid != L.length - 1) {  // 如果找到了x，并且x不是最后一个数，才进行交换
        temp = L.data[mid];
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = temp;
    }
    if (low > high) {   // 没找到，将x插入
        for (i = L.length - 1; i > high; i--) {
            L.data[i+1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.length++;
    }
}


int main() {
    int n, pos, e, del_e, find_e, e_id, x, s, t;
    // 定义一个顺序表结构体并初始化（初始化的方式应该不太对）
    SqList L;

    // 创建顺序表
    printf("Please input the SeqList each element: \n");
    n = ListCreate(L);
    ListPrint(L);

    // 在顺序表指定位pos置插入元素e
    printf("Please input the e element in i position (e, i): \n");
    scanf("%d %d", &e, &pos);
    ListInsert(L, pos+1, e);
    ListPrint(L);

    // 插入后现在有n+1个元素了，然后删除第n个元素
    printf("Delete position %d element\n", n);
    ListDelete(L, n, del_e);
    ListPrint(L);

    // 查找元素
    printf("Please input the number you want to find: \n");
    scanf("%d", &find_e);
    e_id = ListLocateElem(L, find_e);
    if (e_id) {
        printf("The %d element's position is %d\n", find_e, e_id);
    } else {
        printf("Don't exist %d number\n", find_e);
    }

    // 翻转顺序表
    printf("Reverse SeqList\n");
    ListReverse(L);
    ListPrint(L);

    // 删除顺序标中所有元素x
    printf("Please input the all x element you want delete: \n");
    scanf("%d", &x);
    printf("Delete all element %d\n", x);
    ListDeleteAllX1(L, x);
    ListPrint(L);

    // 删除顺序表中所有值在s与t(s<t)的元素
    printf("Please input the s and t: \n");
    scanf("%d %d", &s, &t);
    printf("Delete all element between s and t\n");
    ListDeleteALLST(L, s, t);
    ListPrint(L);

    // 删除有序顺序表中所有重复元素
    printf("Delete all repeating elements in an ordered list\n");
    ListDeleteOrderListRepeatElem(L);
    ListPrint(L);

    // 删除顺序表中所有重复元素
    // Hash表

    // 合并两个有序顺序表 ListMerge()

    // 查找交换插入元素x, ListSearchExchangeInsert
    printf("Please input the x of ListSearchExchangeInsert\n");
    scanf("%d", &x);
    ListSearchExchangeInsert(L, x);
    ListPrint(L);

    // P18 T10 T11 T12 待做




    return 0;
}
