/**
 * Creation         :       2019.04.22 18:14
 * Last Reversion   :       2019.04.22 18:56
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * DP_LISI(最长上升子序列) Leetcode 300
 * 题目描述
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
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
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define INF __INT_MAX__

/**
 * 方法一：动态规划
 * 时间复杂度: O(n^2)
 * 思路：
分析：首先仔细审题，明确题目中的条件。
1、子序列：不要求连续子序列，只要保证元素前后顺序一致即可；
2、上升：这里的“上升”是“严格上升”，类似于 [2, 3, 3, 6, 7] 这样的子序列是不符合要求的；
一个序列可能有多个最长上升子序列，题目中只要我们求这个最长的长度。如果使用回溯搜索，选择所有的子序列进行判断，时间复杂度为 O((2^n)*n)

定义状态：LIS(i) 表示以第 i 个数字为结尾的最长上升子序列的长度。即在 [0, ..., i] 的范围内，选择以数字 nums[i] 结尾可以获得的最长
上升子序列的长度。关键字是：以第 i 个数字为结尾，即我们要求 nums[i] 必须被选取。反正一个子序列一定要以一个数字结尾，那我就将状态这么定义，
这一点是重要且常见的。

状态转移方程：遍历到索引是 i 的数的时候，我们应该把索引是 [0, ... ,i-1] 的 LIS 都看一遍，如果当前的数 nums[i] 大于之前的某个数，
那么 nums[i] 就可以接在这个数后面形成一个更长的 LIS 。把前面的 i 个数都看了， LIS[i] 就是它们的最大值加 1。即比当前数要小的那些里头，
找最大的，然后加 1.

状态转移方程即：LIS(i) = max(dp[i], dp[j]+1),  if j < i and nums[i] > nums[j]
（这里也可以用选不选的思想，选dp[j]，则LIS(i) = dp[j]+1,  不选dp[j]，则LIS(i) = dp[i]）
最后不要忘了，应该扫描一遍这个 LIS[i] 数组，其中最大的就是我们所求的。
 */ 
int LengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    
    int max_len = 0;
    // 定义状态，初始值为1，因为每个位置的最短上升子序列也有1
    int *dp = (int*)malloc(sizeof(int) * (nums.size() + 1));
    for (int i = 0; i < nums.size() + 1; i++)
        dp[i] = 1;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                // 或者写成
                // if (dp[i] < dp[j] + 1) 
                //     dp[i] = dp[j] + 1;
            }
        }
        if (max_len < dp[i])
            max_len = dp[i];
    }
    free(dp);
    return max_len;
}


/**
 * 二分查找，返回数组data中第一个 >= x 的位置
 */ 
int BinarySearch(int *data, int len, int x) {
    int l = 0, r = len, mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (data[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

/**
 * 方法二：二分+贪心
 * 时间复杂度: O(nlogn)
 * 思想：
 *    新建一个low数组，low[i] 表示长度为i的LIS结尾元素的最小值。比如我们有一个数组：nums = [8,4,5,6,3]
 * len = 1   :   [8], [4], [5], [6], [3]   => low[0] = 3，表示长度为1时，递增序列末尾元素的最小值为 3
 * len = 2   :   [4, 5], [5, 6]            => low[1] = 5
 * len = 3   :   [4, 5, 6]                 => low[2] = 6
 * 对于一个上升子序列，显然其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长。因此，我们只需要维护low数组，
 * 对于每一个nums[i]，如果 nums[i] > low[当前最长的LIS长度]，就把 nums[i] 接到当前最长的LIS后面，
 * 即 low[++当前最长的LIS长度] = nums[i]。 
 *    那么，怎么维护low数组呢？ 
 * 对于每一个 nums[i]，如果 nums[i] 能接到LIS后面，就接上去；否则，就用 nums[i] 去更新low数组。具体方法是，在low数组
 * 中找到第一个大于等于 nums[i]的元素 low[j]，用 nums[i] 去更新 low[j]。如果从头到尾扫一遍low数组的话，时间复杂度
 * 仍是O(n^2)。我们注意到low数组内部一定是单调不降的，所有我们可以二分low数组，找出第一个大于等于 nums[i]的元素。
 * 二分一次low数组的时间复杂度的O(lgn)，所以总的时间复杂度是O(nlogn)。
 */ 
int LengthOfLIS2(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    // 新建一个low数组，low[i]表示长度为i的LIS结尾元素的最小值. 初始值为1
    int *low = (int*)malloc(sizeof(int) * (nums.size() + 1));
    for (int i = 0; i < (nums.size() + 1); i++) 
        low[i] = INF;
    // 以上三行可以直接用 vector<int> low(nums.size() + 1, INF); 替换
    low[0] = nums[0];
    int len = 0;  // 初始时，LIS长度为0+1,最后返回值+1了
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > low[len])
            low[++len] = nums[i];
        else
            low[BinarySearch(low, len, nums[i])] = nums[i];
    }
    free(low);
    return len+1;
}

/**
 * 方法二：二分 + 贪心 （优化代码，就是不那么容易理解）
 */ 
int LengthOfLIS3(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    vector<int> low(nums.size(), INF);
    int len = 0;
    for (int index = 0; index < nums.size(); index++) {
        int l = 0, r = len;
        while (l != r) {
            int m = (l + r) / 2;
            if (low[m] < nums[index])
                l = m + 1;
            else 
                r = m;
        }
        low[l] = nums[index];
        if (l == len) ++len;
    }
    return len;
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
    cout << LengthOfLIS3(arr) << endl;;
    return 0;
}