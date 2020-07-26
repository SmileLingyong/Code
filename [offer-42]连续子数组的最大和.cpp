/**
 * Creation         :       2019.04.21 17:07
 * Last Reversion   :       2019.04.21
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FindGreatestSumOfSubArray(连续子数组的最大和)
 * 题目描述
 *    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,
 * 他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量
 * 全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
 * 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和
 * 为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会
 * 不会被他忽悠住？(子向量的长度至少是1)
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一： 举例分析数组的规律.
 * 当前面的连续数字加起来cur_sum <= 0，则我们记录当前连续最大和为 cur_sum = array[i]
 * 若前面连续数字最大和cur_sum > 0，则我们记录当前连续最大和为 cur_sum = cur_sum + array[i]
 * 遍历每个元素的同时，更新最大和
 */
int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.size() <= 0) 
        return 0;
    int cur_sum = 0;    
    int greatest_sum = 0x80000000;      // int的最大负数
    for (int i = 0; i < array.size(); i++) {
        if (cur_sum <= 0) {
            cur_sum = array[i];         // 记录当前最大值
        } else {
            cur_sum += array[i];
        }
        if (cur_sum > greatest_sum) {   // 当array[i]为正数时，加上之前的最大值并更新最大值
            greatest_sum = cur_sum;
        }
    }
    return greatest_sum;
}

/**
 * 方法二： 动态规划方法
 * 定义状态：      dp[i]: 表示到i这个位置，所有连续子向量的最大和。
 * 状态转移方程：   dp[i] = max(d[i-1] + array[i], array[i])
 * 即表示：
 * （1）当以第 i-1 个数字结尾的所有连续子向量和dp[i-1]小于0，此时不考虑用前面的，
 * 直接用array[i]做为该位置的连续子向量最大和
 * （2）当以第 i-1 个数字结尾的所有连续子向量最大和dp[i-1]大于0，则更新dp[i]=d[i-1]+array[i]
 */ 
 int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();
    int *dp = new int[len];
    dp[0] = array[0];
    int greatest_sum = 0x80000000;   // int的最大负数
    for (int i = 1; i < len; i++) {
        // if (dp[i-1] < 0) {
        //     dp[i] = array[i];
        // } else {
        //     dp[i] = dp[i-1] + array[i];
        // } 
        /* 等价于上面注释的部分 */
        dp[i] = max(dp[i-1] + array[i], array[i]);
        greatest_sum = greatest_sum < dp[i] ? dp[i] : greatest_sum;
    }
    delete []dp;
    return greatest_sum;
}


int main() {
    int init[] = {6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> array(init, init + sizeof(init) / sizeof(int));
    cout << FindGreatestSumOfSubArray(array) << endl;
    return 0;
}