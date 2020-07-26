/**
 * Creation         :       2019.04:12 21:13
 * Last Reversion   :       2019.04:12 21:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
HasSubtree(树的子结构)
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


bool DoesAHaveB(TreeNode *A, TreeNode *B) {
    // 如果Tree2已经遍历完了都能对应的上，返回true
    if (B == NULL) 
        return true;
    // 如果Tree2还没有遍历完，Tree1却遍历完了。返回false
    if (A == NULL) 
        return false;
    // 如果其中有一个点没有对应上，返回false
    if (A->val != B->val)
        return false;
    return DoesAHaveB(A->left, B->left) && DoesAHaveB(A->right, B->right);
}

/**
 * 判断B树是否是A的子结构
 */ 
bool HasSubtree(TreeNode *A, TreeNode *B) {
    bool res = false;
    // 当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
    if (A && B) {
        // 如果找到了对应Tree2的根节点的点
        if (A->val == B->val)
            // 以这个根节点为为起点判断是否包含Tree2
            res = DoesAHaveB(A, B);
        // 如果找不到，那么就再去root的左儿子当作起点，去判断时候包含Tree2
        if (!res)
            res = HasSubtree(A->left, B);
        // 如果还找不到，那么就再去root的右儿子当作起点，去判断时候包含Tree2
        if (!res) 
            res = HasSubtree(A->right, B);
    }
    return res;
}

int main() {

    return 0;
}