/**
 * Creation         :       2019.03.24 17:25
 * Last Reversion   :       2019.03.24 20:22
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
FindPath(二叉树中和为某一值的路径)
题目描述
   输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

vector<vector<int> > res;

void FindPathDFS(TreeNode *root, int expectNumber, vector<int> &path, int currentSum) {
    currentSum += root->val;
    path.push_back(root->val);

    // 如果是叶节点，并且路径上节点值的和等于输入的值，则打印出这条路径
    if (currentSum == expectNumber && (root->left == NULL && root->right == NULL)) {
        res.push_back(path);
    }
    // 如果不是叶子节点，则遍历它的子节点
    if (root->left != NULL) {
        FindPathDFS(root->left, expectNumber, path, currentSum);
    }
    if (root->right != NULL) {
        FindPathDFS(root->right, expectNumber, path, currentSum);
    }
    // 返回父节点之前，在路上删除当前节点
    path.pop_back();
}

/**
 * 思想：使用先序遍历 DFS
 */ 
vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
    if (root == NULL) 
        return res;
    vector<int> path;
    int currentSum = 0;
    FindPathDFS(root, expectNumber, path, currentSum);
    return res;
}