/**
 * Creation         :       2019.05.12 16:59
 * Last Reversion   :       2019.05.12 16:59
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * rotate(旋转数组)
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。
 * -----------------------------------------------------------------
 * Reference: http://www.cnblogs.com/grandyang/p/4298711.html
 * -----------------------------------------------------------------
 * Crop last @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法一： 借助辅助数组
 * 复制一个和nums一样的数组，然后利用映射关系 i -> (i+k)%n 交换数字
 * 时间复杂度为 O(n), 空间复杂度为： O(n)
 */
void rotate(vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) return;
    vector<int> t = nums;
    for (int i = 0; i < nums.size(); i++) {
        nums[(i + k) % nums.size()] = t[i];
    }
}

/**
 * 方法二：不适用辅助数组，只是用一个数组空间
 * 空间复杂度： O(1)
 */ 
void rotateII(vector<int> &nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) return;
    int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
    for (int i = 0; i < n; ++i) {
        pre = cur;
        idx = (idx + k) % n;
        cur = nums[idx];
        nums[idx] = pre;
        if (idx == start) {
            idx = ++start;
            cur = nums[idx];
        }
    }
}

/**
 * 方法三： 翻转字符串的思路
 * 先把前 n-k 个数字翻转一下，然后再把后 k 个数字翻转一下，最后再把真个数组翻转一下
 * 例如如下： k = 3
 * a b c d | e f g
 * d c b a | e f g
 * d c b a | g f e
 * e f g | a b c d
 */ 
void rotateIII(vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) return;
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

/**
 * 方法四：使用STL库来操作
 * 从数组末尾取k个数组放入数组的开头
 */ 
void rotateIV(vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) return;
    int n = nums.size();
    for (int i = 0; i < n - k; ++i) {
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}


int main() {
    vector<int> nums;
    int x, k;
    while (cin >> x && x != 9999) {
        nums.push_back(x);
    }
    cout << "请输入数组每个元素需要向右移动几位:";
    cin >> k;
    rotateIII(nums, k);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}