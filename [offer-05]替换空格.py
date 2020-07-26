# -*- coding: utf-8 -*-
#  -----------------------------------------------------------------
#  Creation         :       2019.06.28 12:03
#  Last Reversion   :       2019.06.28 12:03
#  Author           :       Lingyong Smile {smilelingyong@163.com}
#  File Type        :       python
#  -----------------------------------------------------------------
#  ReplaceSpace(替换空格)
#  题目描述
#     请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为
#  We Are Happy。 则经过替换之后的字符串为We%20Are%20Happy。
#  -----------------------------------------------------------------
#  Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}

class Solution:

    def replaceSpace(self, s):
        """
        方法一：使用split将s字符串按空格进行分割，然后再使用join函数，让字符串之间使用%20进行连接
        :param s:   输入的字符串
        :return:    返回替换后的字符串
        """
        return "%20".join(list(s.split(" ")))

    def replaceSpace(self, s):
        """
        方法二：使用替换函数
        :param s:
        :return:
        """
        return s.replace(' ', '%20')

    def replaceSpaceIII(self, s):
        """
        方法三：使用的指针的方式遍历，在原有的字符串上进行修改，先计算替换后的字符串长度，然后设置两个指针，
        分别指向替换前字符串的末尾p1，和替换后字符串的末尾p2，然后从后往前做替换：
            如果p1指向的内容不是空格，则将p1指向的内容复制到p2，p1--; p2--;；
            如果p1直线的内容是空格，则将空格替换成%20，p2边替换边--; p1--;
            直至遍历完整个数组。
        :param s:   输入的字符串
        :return:    返回替换后的字符串
        """
        if s == "":
            return ""

        s_new = ''
        for i in range(len(s)):
            if s[i] != ' ':
                s_new += s[i]   # 字符串string追加使用 += 即可
            else:
                s_new += '%20'
        return s_new


if __name__ == '__main__':
    str = input()
    solution = Solution()
    print(solution.replaceSpaceIII(str))
