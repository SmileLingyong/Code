/**
 * Creation         :       2019.08.26 15:01
 * Last Reversion   :       2019.08.22 15:01
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
颜色分类
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]

进阶：
一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Swap(int &a, int &b);

/**
 * 方法一：直接排序
 */
void sortColors(vector<int> &nums) {
    sort(nums.begin(), nums.end());
}

/**
    方法二：使用三指针
    p0：0的最右边界
    p2：2的最左边界
    cur：当前考虑的元素  (手动Debug一遍下面的例子就明白了)

            p0               p2
            |                 |
    nums:  [1   0   2    1    1    2]
            |
            cur

    沿着数组移动cur指针
    若 nums[cur] == 0, 则将其与nums[p0] 互换
    若 nums[cur] == 2，则与nums[p2] 互换

    【具体算法】
    初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.
    初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.
    初始化当前考虑的元素序号 ：curr = 0.
    While curr <= p2 :
    若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。
    若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。
    若 nums[curr] = 1 ：将指针curr右移。
 */
void sortColorsII(vector<int> &nums) {
    int p0 = 0, cur = 0;
    int p2 = nums.size() - 1;
    while (cur <= p2) {
        if (nums[cur] == 0) {
            Swap(nums[cur], nums[p0]);
            cur++;
            p0++;
        } else if (nums[cur] == 2) {
            Swap(nums[cur], nums[p2]);
            p2--;
        } else {
            cur++;
        }
    }
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int main() {
    vector<int> nums = {1, 2, 0, 1, 1, 0};
    sortColorsII(nums);
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) 
        cout << *iter << " ";
    cout << endl;
    return 0;
}