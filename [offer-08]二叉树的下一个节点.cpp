/**
 * Creation         :       2019.03.18 14:00
 * Last Reversion   :       2019.03.18 14:40
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GetNext(二叉树的下一个节点)
 * 题目描述
 *    给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>

typedef struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *pre;
} TreeLinkNode;

/**
 * 思路：
 * 1. 如果一个节点的右子树不为空，那么该节点的下一个节点是右子树的最左节点；
 * 2. 如果一个节点的右子树为空，则找第一个当前节点是父节点左孩子的节点
 *      (1) 如果该节点是它父节点的左子节点，那么它的下一个节点就是它的父节点
 *      (2) 如果该节点右子树为空，并且它还是它父节点的右子节点，我们需要沿着指向父节点
 *          的指针一直向上遍历，直到找到一个是它父节点的左子节点的节点。如果这样的节点存在，
 *          那么这个节点的父节点就是我们要找的下一个节点。
 */ 
TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    if (pNode == NULL)
        return NULL;
    if (pNode->right != NULL) {     // 如果有右子树，则找右子树的最左节点
        pNode = pNode->right;
        while (pNode->left != NULL)
            pNode = pNode->left;
        return pNode;
    } 
    while (pNode->pre != NULL) {   // 没右子树，则找第一个当前节点是父节点左孩子的节点
        if (pNode->pre->left == pNode)
            return pNode->pre;
        pNode = pNode->pre;
    }
    return NULL;                    // 退到了根节点仍没找到，则返回 NULL
}