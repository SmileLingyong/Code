/**
 * Creation         :       2019.06.30 10:36
 * Last Reversion   :       2019.06.30 10:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Number of Longest Increasing Subsequence(最长上升子序列的个数) Leetcode 673
 * 题目描述
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4

解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * -----------------------------------------------------------------
结合PPT动态图解释理解： 
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;
#define INF 0x7fffffff

/**
 * 方法一：动态规划
 * 时间复杂度：O(n^2)
 * 维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，对于每一个nums[i]，
 * 我们从第一个数再搜索到i，如果发现某个数小于nums[i]，我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，
 * 即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，我们就这样不断的更新dp数组，到最后
 * dp数组中最大的值就是我们要返回的LIS的长度
 */ 
int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);    
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}


/**
 * 二分查找：在有序数组 tail 中查找第 1 个大于等于 num 的那个数，试图让它变小。
 */ 
int BinarySearch(vector<int> data, int len, int x) {
    int l = 1, r = len, mid;
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
 * 方法二：贪心 + 二分查找方法
 * 时间复杂度为 O(nlogn)
1、设置一个有序数组 tail，初始时为空；
2、在遍历数组 nums 的过程中，每来一个新数 num，如果这个数（严格）大于有序数组 tail 的最后一个元素，就把 num 放在有序数组 tail 的后面，否则进入第 3 点；
3、在有序数组 tail 中查找第 1 个大于等于 num 的那个数，试图让它变小。
4、遍历新的数 num 使用上述第 2 点或者第 3 点，直到遍历完整个数组 nums，最终有序数组 tail 的长度，就是所求的“最长上升子序列”的长度。

以上算法能够奏效的原因是：
1、如果前面的数越小，后面接上一个随机数，就会有更大的可能性构成一个更长的“上升子序列”。
2、可以认为是一种“贪心选择”的思想，只要让前面的数尽量小，在算法的执行过程中，第 2 点被执行的机会就更多。
在有序数组 tail 中找大于等于 num 的第 1 个数，可以使用“二分法”。下面看一个具体的例子，以理解算法的执行流程。
（结合参考的PPT，动态演示理解）
以下两点注意事项：
1、虽然有序数组 tail 是升序数组，但是这个数组并不是每时每刻都表示题目要求的那个“最长上升子序列”，这一点你可以在我上面的例子中找到例证；
2、“贪心算法”保证了算法流程的第 2 点有更多机会被执行。
 */
int lengthOfLISII(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    vector<int> low(nums.size()+1, INF);
    low[1] = nums[0];
    int len = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > low[len]) 
            low[++len] = nums[i];
        else
            low[BinarySearch(low, len, nums[i])] = nums[i];
    }
    return len;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长上升子序列长度为： " << lengthOfLIS(nums) << endl;
    return 0;
}