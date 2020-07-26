/**
 * Creation         :       2019.03.18 15:36
 * Last Reversion   :       2019.03.18 15:45
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
GetNext(二叉树的镜像)
题目描述
     操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
    二叉树的镜像定义：
          源二叉树
             8
           /   \
          6     10
         / \    / \
        5   7  9   11
          镜像二叉树
             8
           /   \
         10     6
        / \    / \
       11  9  7   5
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void Mirror(TreeNode *pRoot) {
    if (pRoot) {
        TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
        temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}