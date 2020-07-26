/**
 * Creation         :       2019.05.08 14:15
 * Last Reversion   :       2019.05.08 14:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
TwoSum(两数之和)
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * 方法一：暴力求解，两层循环遍历
 * 时间复杂度：O(n^2)
 */ 
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
}

/**
 * 方法二：使用HashMap
 * 先遍历一遍数组，将对应的 <key, idx> 存储起来，然后再遍历一遍数组，当前为 nums[i]
 * 则 和为target的另一半为 t = target-nums[i]，我们只要查看该 t 是否再HashMap中，
 * 如果存在，不是当前的 nums[i]，则说明找到，返回对应的两个下标即可。
 * 
 * 例如： [2, 4, 5]，target = 4 
 * 当nums[i] = 2时，t = target[nums[i]] = 2，也是2
 * 查找 data_map[2] == 0, 0 == i，说明就是当前的nums[i]，则不能使用，继续遍历
 * 下一个元素。
 * Reference：https://leetcode-cn.com/problems/two-sum/solution/jie-suan-fa-1-liang-shu-zhi-he-by-guanpengchn/
 */ 
vector<int> twoSumIII(vector<int>& nums, int target) { 
    unordered_map<int, int> data_map;
    vector<int> res;
    // 记录每个数字的下标，建立 <key, idx> 对应关系
    for (int i = 0; i < nums.size(); i++) {
        data_map[nums[i]] = i;     // 重复的数字会被覆盖，但没关系，题目说明只有唯一一个结果
    }

    // 从头开始遍历每个 nums[i]，如果 target-nums[i]在map中，并且不是当前这个nums[i]
    // 则说明找到了两个和为target的数，返回其对应下标
    for (int i = 0; i < nums.size(); i++) {
        int t = target - nums[i];
        if (data_map.count(t) && data_map[t] != i) {
            res.push_back(i);
            res.push_back(data_map[t]);
            break;
        }
    }
    return res;
}

/**
 * 方法三：以上的精简版
 */ 
vector<int> twoSumIV(vector<int>& nums, int target) { 
    unordered_map<int, int> data_map;
    for (int i = 0; i < nums.size(); i++) {
        if (data_map.count(target - nums[i])) {
            return {i, data_map[target - nums[i]]};
        }
        data_map[nums[i]] = i;
    }
    return {};
}



int main() {
    vector<int> vec{2, 2, 4, 3};
    vector<int> res_idx;
    int target = 4;
    res_idx = twoSumIII(vec, target);
    for (int i = 0; i < res_idx.size(); i++) {
        cout << res_idx[i] << " ";
    }
    cout << endl;
    return 0;
}