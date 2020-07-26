/**
 * Creation         :       2019.04.13 11:10
 * Last Reversion   :       2019.04.13 11:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * SerializeBinaryTree(序列化二叉树)
 * 题目描述
 *    请实现两个函数，分别用来序列化和反序列化二叉树
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {}
}TreeNode;

int main() {

    return 0;
}