/**
 * Creation         :       2019.08.19 19:42
 * Last Reversion   :       2019.08.19 19:42
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
滑动窗口的最大值
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int maxVal(vector<int> nums, int l, int r);

/**
 * 方法二：使用双端队列 
 * 时间复杂度为O(n)
 */
vector<int> maxInWindowsII(const vector<int>& num, unsigned int size) {
    vector<int> res;
    deque<int> s;
    int length = num.size();
    if (length == 0 || size <= 0 || length < size) return {};
    for (unsigned int i = 0; i < num.size(); ++i) {
        while (s.size() && num[s.back()] <= num[i])     // 从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            s.pop_back();
        while (s.size() && i - s.front() + 1 > size)    // 当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            s.pop_front(); 
        s.push_back(i);                                 // 把每次滑动的num下标加入队列
        if (size && i + 1 >= size)                      // 当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            res.push_back(num[s.front()]);
    }
    return res;
}

/**
 * 方法一：遍历 时间复杂度为：O(n^2) 超时
 */ 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() <= 0 || k <= 0 || nums.size() < k)
        return {};
    vector<int> res;
    for (int i = 0; i < nums.size() - k + 1; i++) {
        res.push_back(maxVal(nums, i, i + k));
    }
    return res;
}

int maxVal(vector<int> nums, int l, int r) {
    int max_val = nums[l];
    for (int i = l + 1; i < r; i++) {
        max_val = max(max_val, nums[i]);
    }
    return max_val;
}


int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}