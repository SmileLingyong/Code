/**
 * Creation         :       2019.04.22 17:12
 * Last Reversion   :       2019.04.22 17:45
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DP_LIS(最长递增子序列)
 * 题目描述
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:
输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 

示例 2:
输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。

注意：数组长度不会超过10000。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
 * 方法一：（穷举法优化版，使用一个指针搞定）
 */ 
int FindLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    int max_len = 1, count  = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i+1] > nums[i])
            count++;
        else 
            count = 1;
        max_len = count > max_len ? count : max_len;
    }
    return max_len;
}

/**
 * 方法一：（穷举法优化版，使用两个指针）
 */ 
int FindLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    int max_len = 1, count = 1, pre = 0, cur = 1;
    while (cur < nums.size()) {
        if (nums[cur] > nums[pre])
            count++;
        else 
            count = 1;
        max_len = count > max_len ? count : max_len;
        pre = cur;
        cur++;
    }
    return max_len;
}

/**
 * 方法一：（穷举法，自己之前常写的方法，代码写的很不好，很多冗余）
 */ 
int FindLengthOfLCIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1) 
        return 1;
    int max_len = 1, count = 1;
    for (int i = 0, j = 1; j < nums.size(); ) { // 注意，这里要用 j < nums.size()
        int now = i;
        count = 1;
        while (j < nums.size() && nums[i] < nums[j] ) {
            i++;
            j++;
            count++;
            if (max_len < count)
                max_len = count;
        }
        i = now;
        i++;
        j = i + 1;
    }
    return max_len;
}


int main() {
    string str;
    cin >> str;
    vector<int> arr;
    const char *split = "[,]";
    char *p = strtok((char*)str.c_str(), split);
    int num;
    while (p != NULL) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }
    cout << FindLengthOfLCIS(arr) << endl;

    return 0;
}