/**
 * Creation         :       2019.03.17 23:17
 * Last Reversion   :       2019.03.17 23:36
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * 重建二叉树 (reConstructBinaryTree)
 * 题目描述
 *    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入
 * 前序遍历序列 {1,2,4,7,3,5,6,8} 和
 * 中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

/**
 * 先序中序生成树
 */ 
TreeNode *reConstructBinaryTreeCore(vector<int> pre, int pre_s, int pre_e, vector<int> vin, int vin_s,int vin_e) {
    if (vin_s > vin_e)     
        return NULL;

    int key;
    TreeNode *s = (TreeNode*)malloc(sizeof(TreeNode));  
    s->left = s->right = NULL;

    for (int i = vin_s; i <= vin_e; i++) {
        if (vin[i] == pre[pre_s]) {
            key = i;
            break;
        }
    }
    s->val = vin[key];
    s->left  = reConstructBinaryTreeCore(pre, pre_s+1, pre_s+key-vin_s, vin, vin_s, key-1);
    s->right = reConstructBinaryTreeCore(pre, pre_s+key-vin_s+1, pre_e, vin, key+1, vin_e);
    return s;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    return reConstructBinaryTreeCore(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
}

/**
 * 先序遍历
 */ 
void PreOrder(TreeNode *p) {
    if (p) {
        printf("%d", p->val);
        PreOrder(p->left);
        PreOrder(p->right);
    } 
}


int main() {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *T = NULL;
    T = reConstructBinaryTree(pre, vin);
    
    printf("The pre order is = ");
    PreOrder(T);
    printf("\n");

    return 0;
}