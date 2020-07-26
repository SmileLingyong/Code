/**
 * Creation         :       2019.07.02 19:39
 * Last Reversion   :       2019.07.02 19:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
trap(接雨水)
题目描述
给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 上面是由数组
[0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6
个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：根据图像我们可以很容易知道，对于数组中的每个元素位置，我们计算出能接收多少水，计算如下：
 * 当前位置左半部分的最大值max_left, 和右半部分的最大值max_right，选其中较小的那个，减去当前高度值，即
 * 为我们该位置能接受水的高度。(不懂就结合图debug一遍就明白了)
 * 时间复杂度： O(n^2) 数组中的每个元素都需要向左向右扫描。
 * 空间复杂度： O(1) 的额外空间。 
 */

int trap(vector<int> &height) {
    int ans = 0;
    int size = height.size();
    for (int i = 1; i < size - 1; i++) {
        int left_max = 0, right_max = 0;
        for (int j = i; j >= 0; j--) {      // 找到左半部分(0-i)的最高值
            left_max = max(left_max, height[j]);
        }
        for (int j = i; j < size; j++) {    // 找到右半部分(i-size-1的最高值
            right_max = max(right_max, height[j]);
        }
        ans += min(left_max, right_max) - height[i];
    }
    return ans;
}

/**
 * 方法二：在方法一的基础上，我们先把每个位置的 left_max 和 right_max计算好
 * 这样就不用每个位置都要重新 往左遍历一遍，往右遍历一遍。然后最后用一层循环计算每个位置
 * 能接受水的最高高度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */ 
int trapII(vector<int> &height) {
    if (height.empty()) return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i-1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i+1]);
    }
    for (int i = 1; i < size; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}

/**
 * 方法三：使用双指针 （这种方法不熟，要多看多理解）
 * 其实就是在方法二的基础上，进行改进，一次完成遍历。
 * 当 right_max[i] > left_max[i] （元素 0 到元素 6），积水高度将由 left_max 决定，
 * 当 left_max[i]  > right_max[i]（元素 8 到元素 11），积水高度又 right_max 决定，即又较小的那个决定。
 * 然后遍历的同时，维护 left_max, right_max， 即两个指针交替进行
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */ 
int trapIII(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        } else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

/**
 * 方法四：栈的应用 （待完善）
 */ 


int main() { 
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    cout << trapII(height) << endl;
    cout << trapIII(height) << endl;
    return 0; 
}