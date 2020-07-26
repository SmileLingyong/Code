/**
 * Creation         :       2019.07.08 16:19
 * Last Reversion   :       2019.07.08 16:19
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
findKthLargest(数组中的第K个最大元素)
题目描述：
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/**
 * 快速排序中的Partition思想，降序排序
 */  
int Partition(vector<int> &a, int l, int r) {
    int i = l, j = r, key;
    if (l < r) {
        key = a[l];
        while (i < j) {
            while (i < j && a[j] < key) j--;
            if (i < j) 
                a[i++] = a[j];
            while (i < j && a[i] > key) i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = key;
    }
    return i;
}

/**
 * 找到第 k 大的元素
 */ 
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    if (len <= 0) return 0;
    int l = 0, r = len - 1, target = -1;
    int pos = Partition(nums, l, r);
    while (pos != k-1) {
        if (pos > k-1) {
            r = pos - 1;
            pos = Partition(nums, l, r);
        } else {
            l = pos + 1;
            pos = Partition(nums, l, r);
        }
    }
    target = nums[pos];
    return target;
}

int main() {
    string str;
    int k;
    cin >> str;
    cin >> k;
    const char *split = "[,]";
    char *s_input = (char*)str.c_str();
    char *p = strtok(s_input, split);
    int num;
    vector<int> arr;
    while (p) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }   
    cout << findKthLargest(arr, k);
    return 0;
}