/**
 * Creation         :       2019.03.19 00:47
 * Last Reversion   :       2019.03.19 10:12
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Print(把二叉树打印成多行)
 * 题目描述
 *    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
 * 思路：层次遍历，但因为要每行输出该层的所有节点，所以要稍作修改
 */ 
vector<vector<int> > Print(TreeNode *pRoot) {
    TreeNode *p = pRoot;
    vector<vector<int> > res;
    if (p == NULL)
        return res;

    queue<TreeNode *> que;
    que.push(p);
    while (!que.empty()) {
        vector<int> res_layer;
        int lo = 0, hi = que.size();

        while (lo++ < hi) {                 // 每次打印该层的所有节点
            p = que.front();                
            res_layer.push_back(p->val);
            que.pop();
            if (p->left) 
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
        res.push_back(res_layer);
    }
    return res;
}
