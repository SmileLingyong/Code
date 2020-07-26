# -*- coding: utf-8 -*-
# ----------------------------------------------------------------
# Creation         :       2019.04.06 11:30
# Last Reversion   :       2019.04.06 15:39:
# Author           :       Lingyong Smile {smilelingyong@163.com}
# File Type        :       cpp
# -----------------------------------------------------------------
# 题目描述：
#    在如下一堆数字中选出一些数字求和，能够等于数字n。如果存在这样的方案则
# 返回true，否则返回false。arr[] = {3, 34, 4, 12, 5, 2};
# 
# 测试用例：
#  输入：
# 9
# 10
# 11
# 12
# 13
#  输出：
# 1
# 1
# 1
# 1
# 0
# -----------------------------------------------------------------
# Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

import numpy as np 
arr = [3, 34, 4, 12, 5, 2]

def rec_subset(arr, i, s):
    if s == 0:
        return True
    elif i == 0:
        return arr[0] == s
    else:
        A = rec_subset(arr, i-1, s-arr[i])
        B = rec_subset(arr, i-1, s)

rec_subset(arr, len(arr)-1, 9)

def dp_subset(arr, S):
    subset = np.zeros((len(arr), S+1), dtype=bool)
    subset[:, 0] = True
    subset[0, :] = False
    subset[0, arr[0]] = True
    for i in range(1, len(arr)):
        for s in range(1, S+1):
            if arr[i] > s:
                subset[i, s] = subset[i-1, s]
            else:
                A = subset[i-1, s-arr[i]]
                B = subset[i-1, s]
                subset[i, s] = A or B 
    r, c = subset[r-1, c-1]
    return subset[r-1, c-1]


print(dp_subset(arr, 9))
print(dp_subset(arr, 10))
print(dp_subset(arr, 11))
print(dp_subset(arr, 12))
print(dp_subset(arr, 13))