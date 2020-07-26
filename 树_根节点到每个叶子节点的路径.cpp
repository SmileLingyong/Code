/**
 * Creation         :       2019.03.18 20:30
 * Last Reversion   :       2019.03.18 20:
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 输出根节点到每个叶子节点的路径 (BinaryTreeGetPath) 
 * 思想：使用栈
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>
#define MAX_SIZE 100

typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

int i, top = 0;
char pathstack[MAX_SIZE];

/**
 * 输出根节点到每个叶子节点的路径
 */ 
void allPath(BTNode *p) {
    if (p != NULL) {
        pathstack[top] = p->data;       // 让访问的节点入栈，即 p 自上向下走的时候节点入栈
        ++top;
        if (p->lchild == NULL && p->rchild == NULL) {   // 当访问到叶节点时，打印路径
            for (i = 0; i < top; i++)
                printf("%d ", pathstack[i]);
        }
        allPath(p->lchild);             // 处理左子树
        allPath(p->rchild);             // 处理右子树
        --top;                          // 让访问节点出栈（自己手动模拟一遍即可理解）
    }
}