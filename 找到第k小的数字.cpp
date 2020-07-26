/**
 * Creation         :       2019.06.30 20:28
 * Last Reversion   :       2019.06.30 20:35
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
找到第 k 小的数字
基于Partition思想，从无序数组中寻找第 k 大的数字，和快排一样，这里也使用分治的思想。
首先用partition将数组分为两部分，得到分界点下标pos，然后分三种情况：
（1）pos == k-1 则找到第 k 大的值，arr[pos]
（2）pos > k-1, 则第 k 大的值在左边部分的数组
（3）pos < k-1, 则第 k 大的值再右边部分数组
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Partition方法，用于将arr分成两部分，左半边小于第一个元素，右半部分大于第一个元素
 * 时间复杂度： O(nlogn)
 */ 
int Partition(vector<int> &a, int l, int r) {
    int i = l, j = r;
    if (l < r) {
        int key = a[l];
        while (i < j) {
            while (i < j && a[j] > key) j--;
            if (i < j) {
                a[i] = a[j];
                i++;
            }
            while (i < j && a[i] < key) i++;
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = key;
    }
    return i;
}

int find_kth_number(vector<int> &arr, int k) {
    if (arr.size() <= 0) return 0;
    int l = 0, r = arr.size()-1, target;
    int pos = Partition(arr, l , r);
    while (pos != k-1) {
        if (pos > k-1) {
            r = pos - 1;
            pos = Partition(arr, l, r);
        } else {
            l = pos + 1;
            pos = Partition(arr, l, r);
        }
    }
    target = arr[pos];
    return target;
}

int main() {
    // vector<int> arr = {1, 4, 9, 34, 8, 0, 5};
    // int k = 3;
    vector<int> arr = {99, 99};
    int k = 1;
    cout << find_kth_number(arr, k) << endl;
    return 0;
}