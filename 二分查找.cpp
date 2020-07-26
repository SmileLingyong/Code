/**
 * Creation         :       2019.04.30 20:19
 * Last Reversion   :       2019.04.30 20:19
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       c
 * -----------------------------------------------------------------
 * 常用的排序算法
 *      1. 二分查找
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> data, int key) {
    int low = 0, high = data.size() - 1, mid;
    if (low <= high) {
        mid = (low + high) / 2;
        if (key > data[mid])
            low = mid + 1;
        else if (key < data[mid])
            high = mid - 1;
        else 
            return mid;
    }
    return -1;
}

int main() {
    vector<int> data = {1, 2, 3, 4, 4, 4, 5, 7, 8};
    cout << BinarySearch(data, 4) << endl;;
    cout << BinarySearch(data, 6) << endl;
    return 0;
}