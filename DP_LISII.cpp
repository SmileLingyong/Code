/**
 * Creation         :       2019.04.23 11:42
 * Last Reversion   :       2019.04.23 11:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DP_LISII(最长上升子序列的个数) Leetcode 673
 * 题目描述
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:
输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2:
输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

/**
 * 动态规划
 *    在 leetcode300 基础上，多使用一个数组cnt，记录LIS的组合数
 * 自己手动模拟一下： [2,2,3,2,3] 这个序列的情况。
 */ 
int FindNumberOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    int max_len = 1, res = 0;
    vector<int> len(nums.size()+1, 1);
    vector<int> cnt(nums.size()+1, 1);
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (len[i] < len[j] + 1) {          // 如果+1长于当前LIS 则组合数不变
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[i] == len[j] + 1) {  // 如果+1等于当前LIS 则说明找到了新组合
                    cnt[i] += cnt[j];
                }
            }
        }
        max_len = max_len < len[i] ? len[i] : max_len;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (len[i] == max_len)
            res += cnt[i];
    }
    return res;
}

int main() {
    string str;
    vector<int> arr;
    cin >> str;

    const char *split = "[,]";
    char *p = strtok((char*)str.c_str(), split);
    int num;
    while (p) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }
    cout << FindNumberOfLIS(arr) << endl;;
    return 0;
}