/**
 * Creation         :       2019.07.02 18:03
 * Last Reversion   :       2019.07.02 18:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
maxArea(盛最多水的容器)
题目描述
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画
n 条垂直线， 垂直线 i 的两个端点分别为 (i, ai) 和 (i,
0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组
[1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：直接两重循环遍历即可
 * 时间复杂度：O(n^2)  超时！
 */
int maxArea(vector<int> &height) {
    int max_area = 0, area;
    for (int i = 0; i < height.size() - 1; i++) {
        for (int j = i + 1; j < height.size(); j++) {
            area = (j - i) * min(height[i], height[j]); // 以下用一行代码写：max_area = max(max_area, min(height[i], height[j]) * (j - i));
            if (max_area < area) {
                max_area = area;
            }
        }
    }
    return max_area;
}

/**
 * 方法二：双指针法
 * 设置两个指针i，j分别指向收尾，然后我们让高度小的那个往高度高的那边走，虽然 W减小了1，但是最大的面积区间
 * 我们是不会遗漏的，看官方解释
 */ 
int maxAreaII(vector<int> &height) {
    int max_area = 0;
    for (int i = 0, j = height.size()-1; i != j; ) {
        max_area = max(max_area, min(height[j], height[i]) * (j - i));
        if (height[i] < height[j]) 
            i++;
        else 
            j--;
    }
    return max_area;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxAreaII(height) << endl;
    return 0;
}