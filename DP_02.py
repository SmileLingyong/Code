 # -*- coding: utf-8 -*-
 # -----------------------------------------------------------------
 # Creation         :       2019.04.06 11:10
 # Last Reversion   :       2019.04.06 11:23
 # Author           :       Lingyong Smile {smilelingyong@163.com}
 # File Type        :       cpp
 # -----------------------------------------------------------------
 # 题目描述：
 #    在如下一堆数字中选出一些数字，如何让数字之和最大？
 # 限定条件：选出的数字不能是相邻的。
 # arr[7] = {1, 2, 4, 1, 7, 8, 3}
 # -----------------------------------------------------------------
 # Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

 arr = [1, 2, 4, 1, 7, 8, 3]

 def rec_opt(arr, i):
     if i == 0:
         return arr[0]
     elif i == 1:
        return max(arr[0], arr[1])
     else:
        A = rec_opt(arr, i - 2) + arr[i]
        B = rec_opt(arr, i - 1)
        return max(A, B)

# rec_opt(arr, 6)

def dp_opt(arr):
    opt = np.zeros(len(arr))
    opt[0] = arr[0]
    opt[1] = max(arr[0], arr[1])
    for i in range(2, len(arr)):
        A = opt[i-2] + arr[i]
        B = opt[i-1]
        opt[i] = max(A, B)
    return opt[len(arr) - 1]

dp_opt(arr)