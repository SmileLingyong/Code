/**
 * Creation         :       2019.07.12 11:36
 * Last Reversion   :       2019.07.12 12:13
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
threeSumClosest (最接近的三数之和)
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * 方法一：先排序，然后不断缩小范围
 * 排序后固定一个数 nums[i]，然后再使用左右指针指向nums[i]后面的两端
 * 数字分别为nums[L]和nums[R]，计算三个数之和sum，以及与target之间的差dist
 * （1）如果 dis == 0 的话，直接返回sum
 * （2）如果 dis > 0 的话，R-- 即让 sum 变大，dis变小 
 * （3）如果 dis < 0 的话，L-- 即让 sum 变小，dis变大
 * 如果找到更小的 abs(dis) 我们更新最终 min_sum = sum
 */ 
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (len < 3) return 0;
    int sum, dis = 0, L, R, min_dis = 1 << 31 - 1, min_sum;
    for (int i = 0; i < len; i++) {
        L = i + 1;
        R = len - 1;
        while (L < R) {
            sum = nums[i] + nums[L] + nums[R];
            dis = sum - target;
            if (dis == 0) {
                return sum;
            } else if (dis > 0) {
                R--;
            } else if (dis < 0) {
                L++;
            }
            if (abs(dis) < min_dis) {
                min_dis = abs(dis);
                min_sum = sum;
            }
        }
    }
    return min_sum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << threeSumClosest(nums, target) << endl;
    return 0;
}