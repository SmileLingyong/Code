/**
 * Creation         :       2019.07.19 00:41
 * Last Reversion   :       2019.07.19 00:52
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FindNumbersWithSum (和为s的两个数字)
 * 题目描述
 *    输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法一：暴力，两层循环，每次找到一对和为sum的，就与res中的比较积，如果当前的更小
 * 则清除res中的，把当前的两个数加入。直到遍历完全。
 * 时间复杂度：O(n^2) [加了剪枝处理就通过了]
 */ 
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    if (array.size() < 2) return {};
    vector<int> res;
    for (int i = 0; i < array.size() - 1; i++) {
        if (i > 0 && array[i] == array[i-1]) continue;  // 增加剪枝处理
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] + array[j] == sum) {
                if (res.empty()) {
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                } else {
                    if (array[i] * array[j] < res[0] * res[1]) {
                        res.clear();
                        res.push_back(array[i]);
                        res.push_back(array[j]);
                    }
                }
            }
        }
    }
    return res;
}

/**
 * 方法二：使用两个指针处理
 * 排序数组，和相等的两个数，头尾相差越远，其乘积越小，所以从两端开始遍历，找到了两个和为s的，
 * 此时就是乘积最小的。
 * 时间复杂度为： O(n)
 */ 
vector<int> FindNumbersWithSumII(vector<int> array, int sum) {
    if (array.size() < 2) return {};
    int left = 0, right = array.size() - 1, cur_sum;
    vector<int> res;
    while (left < right) {
        if (left > 0 && array[left] == array[left - 1]) {
            left++;
            continue;   // 剪枝处理 
        } 
        cur_sum = array[left] + array[right];
        if (cur_sum < sum) {
            left++;
        } else if (cur_sum == sum) {
            if (res.empty()) {
                res.push_back(array[left]);
                res.push_back(array[right]);
            } else {
                if (array[left] * array[right] < res[0] * res[1]) {
                    res.clear();
                    res.push_back(array[left]);
                    res.push_back(array[right]);
                }
            }
            left++;
        } else {
            right--;
        }
    }
    return res;
}


/**
 * 方法二：使用头尾两个指针处理
 * 排序数组，和相等的两个数，头尾相差越远，其乘积越小，所以从两端开始遍历，找到了两个和为s的，
 * 此时就是乘积最小的，中间的都不需要判断了。
 * 时间复杂度为： O(n)
 */ 
vector<int> FindNumbersWithSumIII(vector<int> array, int sum) {
    if (array.size() < 2) return {};
    int left = 0, right = array.size() - 1, cur_sum;
    vector<int> res;
    while (left < right) {
        if (left > 0 && array[left] == array[left - 1]) {
            left++;
            continue;   // 剪枝处理 
        } 
        cur_sum = array[left] + array[right];
        if (cur_sum < sum) {
            left++;
        } else if (cur_sum == sum) {
            res.push_back(array[left]);
            res.push_back(array[right]);
            break;  // 退出循环
        } else {
            right--;
        }
    }
    return res;
}

int main() {
    vector<int> array = {1, 2, 2, 3, 3, 4, 5, 7};
    int sum = 9;
    // vector<int> res = FindNumbersWithSum(array, sum);
    vector<int> res = FindNumbersWithSumIII(array, sum);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}