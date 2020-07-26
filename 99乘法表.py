# -*- coding: UTF-8 -*-
# -----------------------------------------------------------------
# Creation         :       2019.03.08 21:26
# Last Reversion   :       2019.03.08 21:26
# Author           :       Lingyong Smile {smilelingyong@163.com}
# File Type        :       c
# -----------------------------------------------------------------
# 99 multiplication table
#      This function is to calculate 99 multiplication table.
# -----------------------------------------------------------------
# Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}


def Multiplication():
    for i in range(1, 10):
        for j in range(1, i + 1):
            print('{}x{}={}\t'.format(j, i, j * i), end='')
        print()


Multiplication()