# -*- coding: utf-8 -*-
# Creation         :       2019.05.06 23:34
# Last Reversion   :       2019.05.06 23:49
# Author           :       Lingyong Smile {smilelingyong@163.com}
# File Type        :       python
# -----------------------------------------------------------------
# LinkList (单链表相关知识点)
# -----------------------------------------------------------------
# Reference: https://zhuanlan.zhihu.com/p/45210716
# -----------------------------------------------------------------
# Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

class Node:
    """链表节点类"""
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkList:
    """链表类"""
    def __init__(self):
        self.head = None

    def isempty(self):
        return self.head is None

    def length(self):
        list_len = 0
        p = self.head
        while p:
            p = p.next
            list_len += 1
        return list_len

    def print_list(self):
        p = self.head
        while p is not None:
            print("{}".format(p.val), end=" ")
            p = p.next
        print()

    def add(self, value):
        """头插法创建单链表
              先让新节点的next指向头节点,再将头节点替换为新节点
            顺序不可错，要先保证原链表的链不断，否则头节点后面的链会丢失
        """
        node = Node(value)
        node.next = self.head
        self.head = node

    def append(self, value):
        """尾插法创建单链表
              找到当前节点next为空的位置,然后将next指针指向新插入的节点
        """
        node = Node(value)
        p = self.head
        if self.isempty():
            self.head = node
        else:
            while p.next:
                p = p.next
            p.next = node

    def get_i_elem(self, i):
        """
            按序号 i 查找节点的值,返回node (i 从 0 开始)
        """
        if i == 0:
            return self.head
        if i < 0 or i > self.length() - 1:
            return Node
        else:
            idx = 0
            p = self.head
            while idx < i:
                p = p.next
                idx += 1
            return p

    def get_elem_x(self, x):
        """
            按值查找节点x
        """
        p = self.head
        while p.next != Node and p.val != x:
            p = p.next
        return p

    def insert(self, pos, value):
        """
            在位置pos上插入node
        """
        # 对应特殊情况
        if pos <= 0:
            self.add(value)
        elif pos > len(self) - 1:
            self.append(value)
        else:
            node = Node(value)
            p = self.head
            index = 0
            while index < pos - 1:
                p = p.next
                index += 1
            node.next = p.next
            p.next = node

    def remove(self, pos):
        """
            删除第i个节点
        """
        # 删除第一个节点,则直接将表头后移
        if pos < 0 or pos > self.length()-1:
            print("Error! Please input the right remove pos.")
            return
        elif pos == 0:
            self.head = self.head.next
        else:
            idx = 0
            p = self.head
            while idx < pos-1:
                idx += 1
                p = p.next
            q = p.next
            p.next = q.next

if __name__ == '__main__':
    # 新建一个链表 [1, 2, 3]
    num = int(input("input the linklist size:"), 10)  # 通过使用int()函数指点输入的类型,这里输入为int 10进制类型
    # print(type(num))  # 打印获取的输入元素类型
    L = LinkList()
    for i in range(num):
        x = int(input(), 10)
        L.append(x)  # 尾插法创建链表
    # 打印链表
    L.print_list()
    # 获取索引为0的节点,打印其值
    print(L.get_i_elem(0).val)
    # 获取值为2的节点,打印其值
    print(L.get_elem_x(2).val)
    # 删除最后一个节点
    L.remove(L.length()-1)
    # 打印当前的链表
    L.print_list()
