/**
 * Creation         :       2019.03.18 13:45
 * Last Reversion   :       2019.03.18 13:49
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * TreeDepth(二叉树的深度)
 * 题目描述
 *      输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
 * 形成树的一条路径，最长路径的长度为树的深度。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int TreeDepth(TreeNode *pRoot) {
    int LD, RD;
    if (!pRoot)
        return 0;
    else {
        LD = TreeDepth(pRoot->left);
        RD = TreeDepth(pRoot->right);
        return (LD > RD ? LD : RD) + 1;
    }
}