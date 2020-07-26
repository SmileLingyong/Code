/**
 * Creation         :       2019.03.19 00:12
 * Last Reversion   :       2019.03.19 00:23
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * IsBalanced_Solution(平衡二叉树)
 * 题目描述
 *     输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 平衡二叉树：任意节点的左右子树高度差的绝对值不超过 1
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

int GetDepth(TreeNode *pRoot) {
    TreeNode *p = pRoot;
    if (p == NULL)
        return 0;
    else {
        int LD = GetDepth(p->left);
        int RD = GetDepth(p->right);
        return (LD > RD ? LD : RD) + 1;
    }
}

bool IsBalanced_Solution(TreeNode *pRoot) {
    TreeNode *p = pRoot;
    if (pRoot == NULL)
        return true;
    else {
        if (abs(GetDepth(p->left) - GetDepth(p->right)) > 1 )
            return false;
        else
            return IsBalanced_Solution(p->left) && IsBalanced_Solution(p->right);
    }
}