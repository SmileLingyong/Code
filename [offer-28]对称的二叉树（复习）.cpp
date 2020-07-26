/**
 * Creation         :       2019.03.19 00:31
 * Last Reversion   :       2019.03.19 00:39
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
IsSymmetrical(对称的二叉树)
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

bool isSymmetricalCore(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot1 == NULL && pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;
    if (pRoot1->val != pRoot2->val)
        return false;
    return isSymmetricalCore(pRoot1->left, pRoot2->right) && isSymmetricalCore(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode *pRoot) {
    return isSymmetricalCore(pRoot, pRoot);
}