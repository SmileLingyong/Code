# -*- coding: utf-8 -*-
# -----------------------------------------------------------------
# Creation         :       2019.06.18 21:33
# Last Reversion   :       2019.06.18 21:33
# Author           :       Lingyong Smile {smilelingyong@163.com}
# File Type        :       python
# -----------------------------------------------------------------
# 题目描述
#    在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
# 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
# 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
# 思路：
#    （方法一）：两重循环，每次将第i个，与后面的进行比较，直到找到重复的，或遍历完成。时间复杂度 O(n^2)
#    （方法二）：因为是从0到n-1，如果不重复，那么每个下标和其数应该相等，如果不等，
# 我们就将当前数，交换到其应该在的下标位置。如果，此时要交换的两个数相等，则说明有重复数字。
# 否则遍历完整个序列都不会有重复数字。自己举个例子打一遍即可： [0 1 2 4 3 3] 和 [0 1 2 5 3 4]
#     (方法三)：开辟一个大小为n的数组HashTable，遍历一遍用户输入的数组，将数组中的元素映射到HashTable数组中，
# 比如：用户数组中有5，7，5，就分别将HashTable中下标为5的位置+1，下标为7的位置+1，下标为5的位置再+1，直到遍历
# 完成。那么每个数的出现次数都有了。
# -----------------------------------------------------------------
# Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

class Solution:

    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicateII(self, numbers, duplication):  # 这里传递的参数，其实是传递的是0的对象的引用，而此时的引用duplication，
        # 其实是拷贝的一份引用，和外外面的没有任何关系，如果要获取函数内的参数，需要使用return返回
        """
            剑指offer思想，当元素值不在其对应下标位置，则将其交换到其值所对应的下标位置，自己手动模拟一遍即可理解
        """
        for i in range(len(numbers)):
            while numbers[i] != i:
                if numbers[i] == numbers[numbers[i]]:
                    duplication[0] = numbers[i]     # 注意，这里要使用duplication[0] 表示传入的是一个list列表，否则，无法修改函数外对应传入的参数
                    return True
                temp = numbers[i]
                numbers[i] = numbers[numbers[i]]
                numbers[temp] = temp
        return False

    def duplicateIII(self, numbers, duplication):
        """
            开辟一个长度为n的bool数组has_num，来记录每个位置的数字是否出现过，比如当前数字是5，则把has_num[5]+=1,
            如果下次还出现了5，则可判断有重复数字了。
        """
        has_num = [x * 0 for x in range(0, 100)]
        for each in numbers:
            if has_num[each]:
                duplication[0] = each
                return True
            else:
                has_num[each] += 1
        return False

    def duplicateIV(self, numbers, duplication):
        """
            每次将不存在的元素放入res，然后如果放入的已经在res中，则说明存在重复的
        """
        res = []
        for each in numbers:
            if each in res:
                duplication[0] = each
                return True
            else:
                res.append(each)
        return False


if __name__ == '__main__':
    # duplication = 0  # 直接使用整形变量（即不可变应用对象）传递时，调用函数，函数会拷贝一份该对象的引用，外面的引用和内部没有关系，
                       # 由于此时的引用为numbers，不可变对象，所以函数内修改不会改变外部的引用，需要return来得到修改后的duplication。
    duplication = [0]  # 传递的是list可变对象的引用，函数内外的对象的引用指向同一块内存地址，函数内修改会修改外部的值
    solution = Solution()
    res = solution.duplicateIV([2, 1, 2, 4, 3, 3], duplication)
    # 注意：如果要获取修改后的duplication，需要在函数中return返回
    if res:
        print('存在重复的数字！')
        print(duplication)
    else:
        print('不存在重复的数字！')