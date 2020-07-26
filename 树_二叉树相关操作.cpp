/**
 * Creation         :       2019.03.17 23:42
 * Last Reversion   :       2019.03.19 10:54
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 二叉树相关操作 (BinaryTree)
    假设已知一棵二叉树S的先序和中序遍历序列，请编程求解这棵二叉树并输出它的后序遍历序列。(5分)
    举例：   pred[]/先序：ABDECFG
            inod[]/中序：DBEACGF
            后序遍历是  ：DEBGFCA
    树的结构如下图：
                    A
                  /   \
                 B     C     
               /   \     \     
              D     E     F 
                         / 
                        G   
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX_SIZE 100

typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

/**
 * 定义顺序非循环队列元素，存储节点所在的指针以及节点所在的层次号
 */ 
typedef struct St {
    BTNode *p;      // 节点指针
    int lno;        // 节点所在层次
}St;


/**
 * 先序遍历
 */ 
void PreOrder(BTNode *T) {
    BTNode *p = T;
    if (p) {
        printf("%c", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

/**
 * 中序遍历
 */ 
void InOrder(BTNode *T) {
    BTNode *p = T;
    if (p) {
        InOrder(p->lchild);
        printf("%c", p->data);
        InOrder(p->rchild);
    }
}

/**
 * 后序遍历
 */ 
void EndOrder(BTNode *T) {
    BTNode *p = T;
    if (p) {
        EndOrder(p->lchild);
        EndOrder(p->rchild);
        printf("%c", p->data);
    }
}


/**
 * 先序遍历（非递归）
 */ 
void PreOrderNo(BTNode *T) {
    BTNode *p = T;
    stack<BTNode*> stk;
    while (p || !stk.empty()) {
        while (p) {
            printf("%c", p->data);
            stk.push(p);
            p = p->lchild;
        } 
        if (!stk.empty()) {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}


/**
 * 中序遍历（非递归）
 */ 
void InOrderNo(BTNode *T) {
    BTNode *p = T;
    stack<BTNode*> stk;             // 初始化栈
    while (p || !stk.empty()) {     // 栈不为空或p不为空是循环
        while (p) {         
            stk.push(p);            // 根指针进栈，遍历左子树
            p = p->lchild;          // 每遇到非空二叉树先向左走
        }
        if (!stk.empty()){          // 若其左孩子为空，
            p = stk.top();          // 则取栈顶元素并进行出栈操作，访问该栈顶结点
            printf("%c", p->data);  
            stk.pop();
            p = p->rchild;          // 然后将当前的P置为栈顶结点的右孩子
        }
    }
}

// Todo: 参考别人的代码，后面要自己理解再写一遍才行（多看几遍！）
/**
 * 后序遍历（非递归） 
 */ 
void EndOrderNo(BTNode *T) {
    stack<BTNode *> s;
    BTNode *cur;                    // 当前结点
    BTNode *pre = NULL;             // 前一次访问的结点
    s.push(T);
    while (!s.empty()) {
        cur = s.top();
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << "";  // 如果当前结点没有孩子结点或者孩子节点都已被访问过
            s.pop();
            pre = cur;
        } else {
            if (cur->rchild != NULL) s.push(cur->rchild);
            if (cur->lchild != NULL) s.push(cur->lchild);
        }
    }
}

/**
 * 层次遍历
 */ 
void LeverOrder(BTNode *T) {
    BTNode *p = T;
    int front, rear;
    BTNode *que[MAX_SIZE], *q;                  // 定义个循环队列
    front = rear = 0;                           // 初始化队列
    if (p) {        
        rear = (rear + 1) % MAX_SIZE;
        que[rear] = p;                          // 根节点入队
        while (front != rear) {
            front = (front + 1) % MAX_SIZE;     // 根节点入出队
            q = que[front];
            printf("%c", q->data);
            if (q->lchild) {                    // 若左子树非空，则左子树根入队
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->lchild;
            }
            if (q->rchild) {                    // 若右子树非空，则右子树根入队
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->rchild;
            }
        }
    }
}

/**
 * 求树的高度
 */ 
int getDeepth(BTNode *T) {
    BTNode *p = T;
    int LD, RD;
    if (p == NULL) 
        return 0;
    else {
        LD = getDeepth(p->lchild);
        RD = getDeepth(p->rchild);
    }
    return (LD > RD ? LD : RD) + 1;
}

/**
 * 求树总节点个数
 */ 
int getCount(BTNode *T) {
    BTNode *p = T;
    int n1, n2;
    if (p == NULL)
        return 0;
    else {
        n1 = getCount(p->lchild);
        n2 = getCount(p->rchild);
        return n1 + n2 + 1;         
    }
}

/**
 * 求树叶节点个数
 */ 
int getLeafNumber(BTNode *T) {
    BTNode *p = T;
    int n1, n2;
    if (p == NULL)
        return 0;
    else if (p->lchild == NULL && p->rchild == NULL)
        return 1;
    else {
        n1 = getLeafNumber(p->lchild);
        n2 = getLeafNumber(p->rchild);
        return n1 + n2;
    }
}

/**
 * 先序中序-->创建树
 */ 
BTNode *PreInCreateBT(char pre[], int pre_s, int pre_e, char in[], int in_s, int in_e) {
    BTNode *s;
    int key;
    if (in_s > in_e)                        // 若序列中没有元素，则树为空，返回NULL
        return NULL;
    
    s = (BTNode*)malloc(sizeof(BTNode));    // 申请一个节点空间
    s->lchild = s->rchild = NULL;

    for (int j = in_s; j <= in_e; j++) {
        if (in[j] == pre[pre_s]) {          // 查找等于当前子树根的节点在 in[]中的位置
            key = j;
            break;
        }
    }

    s->data = in[key];
    s->lchild = PreInCreateBT(pre, pre_s+1, pre_s+key-in_s, in, in_s, key-1);   // 递归建立左子树   
    s->rchild = PreInCreateBT(pre, pre_s+key-in_s+1, pre_e, in, key+1, in_e);   // 递归建立右子树
    return s;
}


/**
 * 中序后序-->创建树
 */ 
BTNode *InEndCreateBT(char in[], int in_s, int in_e, char end[], int end_s, int end_e) {
    BTNode *s;
    int key;
    if (in_s > in_e)
        return NULL;
    
    s = (BTNode*)malloc(sizeof(BTNode));
    s->lchild = s->rchild = NULL;

    for (int j = in_s; j <= in_e; j++) {
        if (in[j] == end[end_e]) {
            key = j;
            break;
        }
    }

    s->data = in[key];
    s->lchild = InEndCreateBT(in, in_s, key-1, end, end_s, end_s+key-in_s-1);
    s->rchild = InEndCreateBT(in, key+1, in_e, end, end_s+key-in_s, end_e-1);
}

/**
 * 思想：利用层次遍历的思想，分别求出每一层节点数量，然后求出数量最大的层。
 * 类似的我们可以实现如下几个功能：
 *    (1)二叉树的宽度
 *    (2)某一层节点个数
 *    (3)每一层节点个数
 */ 
int maxLayerNode(BTNode *T) {
    BTNode *p = T;
    if (p == NULL) 
        return 0;
    St que[MAX_SIZE];
    int front, rear;
    front = rear = 0;
    int Lno, i_layer, j, max, n;
    BTNode *q;
    if (p) {
        ++rear;
        que[rear].p = p;        // 根节点入队
        que[rear].lno = 1;      // 根节点的层号
        while (front != rear) { 
            ++front;           
            q = que[front].p;
            Lno = que[front].lno;   // Lno来存储当前节点的层号
            if (q->lchild) {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }
            if (q->rchild) {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        }   // while循环结束后，Lno保存的是这棵树最大的层号
        max = 0;
        for (i_layer = 1; i_layer <= Lno; i_layer++) {
            n = 0;              // 计算每一层有多少个节点
            for (j = 1; j <= rear; j++) {
                if (que[j].lno == i_layer)
                    ++n;
                if (max < n)
                    max = n;
            }
        }
        return max;
    } else {
        return 0;
    }
}

/**
 * 之字形打印二叉树
 * 思想：使用两个栈。
 * 当我们在打印某一层节点时，把下一层的子节点保存到相应的栈里。
 * 如果当前打印的是奇数层（第一层、第三层），则先保存左子节点再保存右子节点到第一个栈
 * 如果当前打印的是偶数层（第二层、第四层），则先保存右子节点再保存左子节点到第一个栈
 * （自己画图理一下就清楚了）
 */
vector<vector<int> > Print(BTNode* pRoot) {
    BTNode *p = pRoot;
    vector<vector<int> > res;
    if (p) {
        vector<BTNode*> A;
        vector<BTNode*> B;
        A.push_back(p);
        
        while (!A.empty() || !B.empty()) {
            if (!A.empty()) {
                vector<int> layer_data;
                while (!A.empty()) {
                    p = A.back();       // 获取栈尾元素
                    layer_data.push_back(p->data);
                    A.pop_back();       // 栈尾元素出栈
                    B.push_back(p->lchild);
                    B.push_back(p->rchild);
                }
                res.push_back(layer_data);
            } else {
                vector<int> layer_data;
                while (!B.empty()) {
                    p = B.back();
                    layer_data.push_back(p->data);
                    B.pop_back();
                    A.push_back(p->rchild);
                    A.push_back(p->lchild);
                }
                res.push_back(layer_data);
                layer_data.clear();
            }
        }
    }
    return res;
}

int main() {
	char pre[] = {'A','B','D','E','C','F','G'};
	char in[]  = {'D','B','E','A','C','G','F'};
    char end[] = {'D','E','B','G','F','C','A'};

    BTNode *T;

    /* 先序中序 造树 后序输出 */
    printf("Using pre and in create a tree, the end order is as follow :\n");
    printf("pre = %s\nin  = %s\n", pre, in);
    printf("end = ");
    T = PreInCreateBT(pre, 0, strlen(pre)-1, in, 0, strlen(in)-1);      // 构造的树
    EndOrder(T);
    printf("\n");

    /* 非递归版的先序、中序、后续 */
    printf("Non-recursive result is as follow :\n");
    printf("pre = ");
    PreOrderNo(T);
    printf("\n");

    printf("In  = ");
    InOrderNo(T);
    printf("\n");

    printf("In  = ");
    EndOrderNo(T);
    printf("\n");


    /* 中序后序 造树 前序输出 */
    printf("Using in and end create a tree, the pre order is as follow :\n");
	printf("in  = %s\nend = %s\n", in, end);
	printf("pre = ");
    T = InEndCreateBT(in, 0, strlen(in)-1, end, 0, strlen(end)-1);
    PreOrder(T);
    printf("\n");

    /* 层次遍历 */
    printf("Lever order = ");
    LeverOrder(T);
    printf("\n");

    /* 树的高度 */
    printf("The depth of the tree is %d\n", getDeepth(T));

    /* 树总节点个数 */
    printf("Total number of nodes in the tree is %d\n", getCount(T));

    /* 树叶子节点个数 */
    printf("The number of leaf nodes in the tree is %d\n", getLeafNumber(T));

    /* 树的宽度 */
    printf("The width of the tree is %d\n", maxLayerNode(T));

    return 0;
}