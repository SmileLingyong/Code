/**
 * Creation         :       2019.03.22 11:17
 * Last Reversion   :       2019.03.22 11:53
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * KthNode(二叉搜索数的第K大节点)
 * 题目描述
 *    给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如:（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * 思想：根据二叉排序(搜索)数的特点:左子树节点值 < 根节点值 < 右子树节点值
 * 我们通过中序遍历，即可得到一个递增的序列，即可得到第 k 小的数
 * (非递归思想)
 */ 

TreeNode *KthNode(TreeNode *pRoot, int k){
    TreeNode *p = pRoot;
    stack<TreeNode*> stk;
    int i = 0;
    while (p || !stk.empty()) {
        while (p) {
            stk.push(p);
            p = p->left;
        }
        if (!stk.empty()) {
            i++;
            p = stk.top();
            if (i == k)
                return p;
            stk.pop();
            p = p->right;
        }
    }
    return NULL;        // do not forget this!
}
