/**
 * Creation         :       2019.04.23 11:42
 * Last Reversion   :       2019.04.23 11:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Number of Longest Increasing Subsequence(最长上升子序列的个数) Leetcode 673
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
 * Reference: https://www.cnblogs.com/grandyang/p/7603903.html
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
 * 方法一：动态规划 （先把leetcode-300做完再来做这题）
    len[i]是以nums[i]结尾的最长子序列的长度
    cnt[i]是以nums[i]结尾的最长子序列的总数
    (自己最好debug一遍，然后好理解)
 */ 
int FindNumberOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    int max_len = 1, res = 0;
    vector<int> len(nums.size()+1, 1);      // len[i]是以nums[i]结尾的最长子序列的长度;
    vector<int> cnt(nums.size()+1, 1);      // cnt[i]是以nums[i]结尾的最长子序列的总数;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {        // 只有在nums[i] > nums[j]的时候我们才处理，因为nums[i] < nums[j]，加入nums[j]不是递增子序列
                if (len[i] == len[j] + 1)   // 说明nums[i]这个数字可以加在以nums[j]结尾的递增序列后面
                    cnt[i] += cnt[j];       // 并且以nums[j]结尾的递增序列个数cnt[j]可以直接加到以nums[i]结尾的递增序列个数cnt[i]上
                else if (len[i] < len[j] + 1) {     // 如果len[i]小于len[j] + 1，说明我们找到了一条长度更长的递增序列
                    len[i] = len[j] + 1;    // 那么我们此时将len[i]更新为len[j]+1
                    cnt[i] = cnt[j];        // 并且原本的递增序列都不能用了，直接用cnt[j]来代替
                }
            }
        }
        max_len = max(max_len, len[i]);     // max_len = max_len < len[i] ? len[i] : max_len;
    }
    
    // 统计共有多少个最长递增子序列
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
    cout << FindNumberOfLIS(arr) << endl;
    return 0;
}