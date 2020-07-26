/**
 * Creation         :       2019.03.19 10:28
 * Last Reversion   :       2019.03.19 10:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * PrintFromTopToBottom(从上往下打印二叉树)
 * 题目描述
 *    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * 思想：层次遍历
 */ 
vector<int> PrintFromTopToBottom(TreeNode *root) {
    TreeNode *p = root;
    vector<int> res;
    if (p == NULL) 
        return res;
    
    queue<TreeNode*> que;
    que.push(p);
    while (!que.empty()) {
        p = que.front();
        res.push_back(p->val);
        que.pop();

        if (p->left)
            que.push(p->left);
        if (p->right)
            que.push(p->right);
    }
    return res;
}