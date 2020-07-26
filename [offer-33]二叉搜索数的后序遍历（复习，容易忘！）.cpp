/**
 * Creation         :       2019.03.24 16:48
 * Last Reversion   :       2019.03.24 17:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
VerifySquenceOfBST(二叉搜索树的后序遍历)
题目描述
   输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
例如： 2 1 4 3 6 9 7 5 
结果： Right
思路：
   BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，
后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。完美的递归定义。
如果存在前一段中有数字大于x，或者后一段中有数字小于x，则说明不符合。
               5
         3          7   
     1       4    6     9
       2
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool IsEndOrd(vector<int> sequence, int start, int end) {
    if (end <= start) 
        return true;
    // 二叉搜索树中左子树节点的值小于根节点的值，找到分界点
    int i = start;
    for (; i < end; i++) {
        if (sequence[i] > sequence[end]) {
            break;
        }
    }
    // 二叉树右子树节点值大于根节点的值
    for (int j = i; j < end; j++) {
        if (sequence[j] < sequence[end]) {
            return false;
        }
    }
    // 递归判断左右子树是否是二叉搜索树
    return IsEndOrd(sequence, start, i - 1) && IsEndOrd(sequence, i, end - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() == 0)
        return false;
    else
        return IsEndOrd(sequence, 0, sequence.size() - 1);
}

int main() {    
    int n, x;
    vector<int> a;
    printf("Please inuput a int number n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    if (VerifySquenceOfBST(a))
        printf("Right!\n");
    else
        printf("Wrong!\n");
    return 0;
}
