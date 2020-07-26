/**
 * Creation         :       2019.04.30 19:38
 * Last Reversion   :       2019.04.30 19:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * GetNumberOfK(数字在排序数组中出现的次数)
 * 题目描述
 *    统计一个数字在排序数组中出现的次数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：有序，直接遍历
 * 时间复杂度： O(n)
 */ 
int GetNumberOfK(vector<int> data ,int k) {
    int count = 0;
    for (int i = 0; i < data.size(); ) {
        while (data[i] == k) {
            count++;
            i++;
        }
        if (data[i] > k)
            break;
        i++;
    }
    return count;
}

/* ------------------------------------------------------------- */

/**
 * 二分查找
 */ 
int BinarySearch(vector<int> data, double key) {
    int l = 0, r = data.size() - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (data[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

/**
 * 方法二：使用二分查找，查找k+0.5的索引 和 k-0.5的索引，然后相减即可
 */ 
int GetNumberOfKII(vector<int> data ,int k) {
    return BinarySearch(data, k+0.5) - BinarySearch(data, k-0.5);
}

/* ------------------------------------------------------------- */

/**
 * 查找第一个大于等于k的数
 */ 
int BinarySearchIII(vector<int> &data, int k) {
    int l = 0, r = data.size() - 1, mid;
    while (l != r) {            // 注意这里是 != 
        mid = (l + r) / 2;
        if (data[mid] < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

/**
 * 查找最后一个小于等于k的数
 */ 
int BinarySearchIV(vector<int> data, int k) {
    int l = 0, r = data.size() - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (data[mid] <= k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

/**
 * 方法三：使用两次二分查找
 * 先查找第一个大于等于k的索引，然后再查找最后一个小于等于k的索引
 */ 
int GetNumberOfKIII(vector<int> data ,int k) {
    return BinarySearchIV(data, k) - BinarySearchIII(data, k) + 1;
}


int main() {
    vector<int> data = {1, 2, 2, 2, 3, 4, 5, 6, 10,1};
    int k = 2;
    cout << GetNumberOfK(data, k) << endl;
    cout << GetNumberOfKII(data, k) << endl;
    cout << GetNumberOfKIII(data, k) << endl;
    return 0;
}