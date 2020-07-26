# -*- coding: utf-8 -*-
#  Creation         :       2019.06.28 11:45
#  Last Reversion   :       2019.03.08 11:48
#  Author           :       Lingyong Smile {smilelingyong@163.com}
#  File Type        :       python
#  -----------------------------------------------------------------
#  ArrayFind(二维数组中的查找)
#  题目描述
#     在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右
#  递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
#  输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#  例如：
#       1   2   8   9
#       2   4   9   12
#       4   7   10  13
#       6   8   11  15
#  如果查找数字 7，则返回true
#  如果查找数字 5，则放回false
#  -----------------------------------------------------------------
#  Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

class Solution:

    def Find(self, target, array):
        """
        方法一：直接二重循环遍历判断，时间复杂度为 O(n^2)
        :param target:  要查找的数字
        :param array:   要查找的二维列表
        :return:        是否存在，True or False
        """
        for i in range(len(array)):
            for j in range(len(array[0])):
                if target == array[i][j]:
                    return True
        return False

    def FindII(self, target, array):
        """
        方法二：利用二维数组排序的规则，进行遍历
        :param target:  要查找的数字
        :param array:   要查找的二维列表
        :return:        是否存在，True or False
        """
        rows = len(array)
        cols = len(array[0])
        i = rows - 1  # 从最左下角开始遍历
        j = 0
        while i >= 0 and j < cols:
            if target == array[i][j]:  # 相等，返回找到的结果
                return True
            if target < array[i][j]:  # target更小，则往上一行移动
                i = i - 1
                continue
            if target > array[i][j]:  # target更大，则往左一列移动
                j = j + 1
                continue
        return False


if __name__ == '__main__':
    rows = int(input('rows: '))
    cols = int(input('cols: '))
    array = [[0 for i in range(cols)] for j in range(rows)]  # 使用列表生成器创建二维列表
    print('请输入二维列表：')
    for i in range(rows):
        for j in range(cols):
            array[i][j] = int(input())
    target = int(input('target: '))

    solution = Solution()
    if solution.Find(target, array):
        print('存在该数字: ', target)
    else:
        print('不存在该数字: ', target)
