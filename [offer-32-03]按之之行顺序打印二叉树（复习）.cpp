/**
 * Creation         :       2019.03.24 20:59
 * Last Reversion   :       2019.03.25 13:00
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Print(按之之行顺序打印二叉树)
 * 题目描述
 *    请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 100

typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * 定义顺序非循环队列元素，存储节点所在的指针以及节点所在的层次号
 */ 
typedef struct St {
    TreeNode *p;      // 节点指针
    int lno;        // 节点所在层次
}St;


/**
 * 先序遍历
 */ 
void PreOrder(TreeNode *T) {
    TreeNode *p = T;
    if (p) {
        printf("%c", p->val);
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

/**
 * 中序遍历
 */ 
void InOrder(TreeNode *T) {
    TreeNode *p = T;
    if (p) {
        InOrder(p->left);
        printf("%c", p->val);
        InOrder(p->right);
    }
}

/**
 * 后序遍历
 */ 
void EndOrder(TreeNode *T) {
    TreeNode *p = T;
    if (p) {
        EndOrder(p->left);
        EndOrder(p->right);
        printf("%c", p->val);
    }
}

/**
 * 层次遍历
 */ 
void LeverOrder(TreeNode *T) {
    TreeNode *p = T;
    int front, rear;
    TreeNode *que[MAX_SIZE], *q;                // 定义个循环队列
    front = rear = 0;                           // 初始化队列
    if (p) {        
        rear = (rear + 1) % MAX_SIZE;
        que[rear] = p;
        while (front != rear) {
            front = (front + 1) % MAX_SIZE;     // 根节点入队
            q = que[front];
            printf("%c", q->val);
            if (q->left) {                      // 若左子树非空，则左子树根入队
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->left;
            }
            if (q->right) {                    // 若右子树非空，则右子树根入队
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->right;
            }
        }
    }
}


/**
 * 先序中序-->创建树
 */ 
TreeNode *PreInCreateBT(char pre[], int pre_s, int pre_e, char in[], int in_s, int in_e) {
    TreeNode *s;
    int key;
    if (in_s > in_e)                            // 若序列中没有元素，则树为空，返回NULL
        return NULL;
    
    s = (TreeNode*)malloc(sizeof(TreeNode));    // 申请一个节点空间
    s->left = s->right = NULL;

    for (int j = in_s; j <= in_e; j++) {
        if (in[j] == pre[pre_s]) {              // 查找等于当前子树根的节点在 in[]中的位置
            key = j;
            break;
        }
    }

    s->val = in[key];
    s->left = PreInCreateBT(pre, pre_s+1, pre_s+key-in_s, in, in_s, key-1);   // 递归建立左子树   
    s->right = PreInCreateBT(pre, pre_s+key-in_s+1, pre_e, in, key+1, in_e);   // 递归建立右子树
    return s;
}

/**
 * 之字形打印二叉树
 * 思想：使用两个栈。
 * 当我们在打印某一层节点时，把下一层的子节点保存到相应的栈里。
 * 如果当前打印的是奇数层（第一层、第三层），则先保存左子节点再保存右子节点到第一个栈
 * 如果当前打印的是偶数层（第二层、第四层），则先保存右子节点再保存左子节点到第一个栈
 * （自己画图理一下就清楚了）
 */ 
vector<vector<char> > Print(TreeNode* pRoot) {
    TreeNode *p = pRoot;
    vector<vector<char> > res;
    if (p) {
        vector<TreeNode*> A;
        vector<TreeNode*> B;
        A.push_back(p);
        while (!A.empty() || !B.empty()) {
            if (!A.empty()) {
                vector<char> layer_data;
                while (!A.empty()) {
                    p = A.back();       // 获取栈尾元素
                    layer_data.push_back(p->val);
                    A.pop_back();       // 栈尾元素出栈
                    if (p->left)
                        B.push_back(p->left);
                    if (p->right)
                        B.push_back(p->right);
                }
                res.push_back(layer_data);
            } else {
                vector<char> layer_data;
                while (!B.empty()) {
                    p = B.back();
                    B.pop_back();
                    layer_data.push_back(p->val);
                    if (p->right)
                        A.push_back(p->right);
                    if (p->left)
                        A.push_back(p->left);
                }
                res.push_back(layer_data);
            }
        }
    }
    return res;
}




int main() {
	char pre[] = {'A','B','D','E','C','F','G'};
	char in[]  = {'D','B','E','A','C','G','F'};
    char end[] = {'D','E','B','G','F','C','A'};

    TreeNode *T;

    /* 先序中序 造树 后序输出 */
    printf("Using pre and in create a tree, the end order is as follow :\n");
    printf("pre = %s\nin  = %s\n", pre, in);
    printf("end = ");
    T = PreInCreateBT(pre, 0, strlen(pre)-1, in, 0, strlen(in)-1);      // 构造的树
    EndOrder(T);
    printf("\n");

    vector<vector<char> > res = Print(T);
    vector<vector<char> >::iterator iter;
    vector<char>::iterator it;
    vector<char> vec_tmp;

    for (iter = res.begin(); iter != res.end(); iter++) {
        vec_tmp = *iter;
        for (it = vec_tmp.begin(); it != vec_tmp.end(); it++) {
            printf("%c", *it);
        }
        printf("\n");
    }
    return 0;
}