# -*- coding: utf-8 -*-
# Creation         :       2019.05.07 10:42
# Last Reversion   :       2019.05.07 10:42
# Author           :       Lingyong Smile {smilelingyong@163.com}
# File Type        :       python
# -----------------------------------------------------------------
# BinaryTree (二叉树相关操作)
#    假设已知一棵二叉树S的先序和中序遍历序列，请编程求解这棵二叉树并输出它的后序遍历序列。(5分)
# 举例：   pred[]/先序：ABDECFG
#         inod[]/中序：DBEACGF
#         后序遍历是  ：DEBGFCA
# 树的结构如下图：
#                 A
#               /   \
#              B     C
#            /   \     \
#           D     E     F
#                      /
#                     G
# -----------------------------------------------------------------
# Reference: https://blog.csdn.net/Bone_ACE/article/details/46718683
# -----------------------------------------------------------------
# Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

class Node(object):
    """节点类"""

    def __init__(self, elem=-1, lchild=None, rchild=None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild


class Tree(object):
    """树类"""

    def __init__(self):
        self.root = Node()
        self.myQueue = []

    def add(self, elem):
        node = Node(elem)
        if self.root.elem == -1:  # 如果树是空的,则对根节点赋值
            self.root = node
            self.myQueue.append(self.root)
        else:
            tree_node = self.myQueue[0]  # 此节点的子树还没有设置好
            if tree_node.lchild is None:
                tree_node.lchild = node
                self.myQueue.append(tree_node.lchild)
            else:
                tree_node.rchild = node
                self.myQueue.append(tree_node.rchild)
                self.myQueue.pop(0)

    def pre_in_create_tree(self, pre, pre_s, pre_e, ind, ind_s, ind_e):
        if ind_s > ind_e:
            return None
        for j in range(ind_s, ind_e + 1):
            if ind[j] == pre[pre_s]:
                key = j
                break
        s = Node(ind[key])
        s.lchild = self.pre_in_create_tree(pre, pre_s + 1, pre_s + key - ind_s, ind, ind_s, key - 1)
        s.rchild = self.pre_in_create_tree(pre, pre_s + key - ind_s + 1, pre_e, ind, key + 1, ind_e)
        return s

    def pre_order(self, root):
        """先序遍历(递归)"""
        if root is None:
            return
        print(root.elem, end=" ")
        self.pre_order(root.lchild)
        self.pre_order(root.rchild)

    def in_order(self, root):
        """中序遍历(递归)"""
        if root is None:
            return
        self.in_order(root.lchild)
        print(root.elem, end=" ")
        self.in_order(root.rchild)

    def end_order(self, root):
        """后续遍历(递归)"""
        if root is None:
            return
        self.end_order(root.lchild)
        self.end_order(root.rchild)
        print(root.elem, end=" ")

    def pre_order_no(self, root):
        """先序遍历(非递归)"""
        if root is None:
            return
        stk = []
        node = root
        while node or stk:
            while node:
                print(node.val, end=" ")
                stk.append(node)
                node = node.lchild
            node = stk.pop()
            node = node.rchild

    def in_order_no(self, root):
        """中序遍历(非递归)"""
        if root is None:
            return
        stk = []
        node = root
        while node or stk:
            while node:
                stk.append(node)
                node = node.rchild
            node = stk.pop()
            print(node.val, end=" ")
            node = node.rchild

    def end_order_no(self, root):
        """后续遍历(非递归)"""
        if root is None:
            return
        stk = []
        node = root
        # while


if __name__ == '__main__':
    lever_order = []
    pre = ['A', 'B', 'D', 'E', 'C', 'F', 'G']
    ind = ['D', 'B', 'E', 'A', 'C', 'G', 'F']
    end = ['D', 'E', 'B', 'G', 'F', 'C', 'A']

    tree = Tree()
    # for elem in test:
    #     tree.add(elem)

    tree_a = tree.pre_in_create_tree(pre, 0, len(pre) - 1, ind, 0, len(ind) - 1)

    print("先序遍历(递归):")
    tree.pre_order(tree_a)
    # tree_a.pre_order(tree.root)
    # print()
    #
    # print("中序遍历(递归)")
    # tree.in_order(tree.root)
    # print()
    #
    # print("后序遍历(递归)")
    # tree.end_order(tree.root)
    # print()
