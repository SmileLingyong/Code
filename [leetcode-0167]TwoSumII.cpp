/**
 * Creation         :       2019.05.08 14:15
 * Last Reversion   :       2019.05.08 14:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * TwoSumII(两数之和II-输入有序数组)
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * 方法一：暴力方法(leetcode-0001)
 */ 

/**
 * 方法二：使用unordered_map
 */ 
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < numbers.size(); ++i) {
        m[numbers[i]] = i;
    }
    for (int i = 0; i < numbers.size(); ++i) {
        int t = target - numbers[i];
        if (m.count(t) && m[t] != i) {
            res = {i + 1, m[target-numbers[i]] + 1};
            break;
        } 
    }
    return res;
}

int main() {
    vector<int> vec = {2, 7, 11, 15};
    vector<int> res;
    int target = 9;
    res = twoSum(vec, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}