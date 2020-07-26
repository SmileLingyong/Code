/**
 * Creation         :       2019.04.16 19:16
 * Last Reversion   :       2019.04.16 20:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * MoreThanHalfNumSolution(数组中出现次数超过一半的数字)
 * 题目描述
 *    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入
 * 一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数
 * 组长度的一半，因此输出2。如果不存在则输出0。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

/**
 * 方法一：
 * 使用map来记录每个数字出现的次数，时间复杂度为 O(n)
 */ 
int MoreThanHalfNumSolution(vector<int> numbers) {
    map<int, int> map_num;
    int thresh_hold = numbers.size() / 2;
    for (int i = 0; i < numbers.size(); i++) {
        map_num[numbers[i]]++;
        if (map_num[numbers[i]] > thresh_hold) {    // 如果出现超过一半的数字，则返回该数字
            return numbers[i];
        } 
    }
    return 0;
}

/**
 * 方法二：
 * 先排序，若存在超过一半的数字，则中位数一定是该数字，否则不存在
 */ 
void QuickSort(vector<int> a, int l, int r) {
    int key;
    int i = l, j = r;
    if (l < r) {
        key = a[l];
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
        QuickSort(a, l, i - 1);
        QuickSort(a, i + 1, r);
    }
}

int MoreThanHalfNumSolution2(vector<int> numbers) {
    int len = numbers.size();
    if (len <= 0) {
        return 0;
    }
    QuickSort(numbers, 0, len-1);   // 或者直接使用 sort() 函数
    
    int res = numbers[len / 2];
    int times = 0;
    for (int i = 0; i < len; i++) {
        if (numbers[i] == res)
            times++;
    }
    if (times > len / 2)
        return res;
    else 
        return 0;
}


/**
 * 方法三：基于快排中partition思想，从无序数组中寻找第 k = n/2 大的数字
 * 首先用partition将数组分为两部分，得到分界点下标pos，然后分三种情况：
 * （1）pos == k-1 则找到第 k 大的值，arr[pos]
 * （2）pos > k-1  则第 k 大的值在左边部分的数组
 * （3）pos < k-1  则第 k 大的值再右边部分数组
 */ 
int Partition(vector<int> &a, int l, int r) {
    int i = l, j = r, key;
    if (l < r) {
        key = a[l];
        while (i < j) {
            while (i < j && a[j] > key) j--;
            if (i < j) 
                a[i++] = a[j];
            while (i < j && a[i] < key) i++;
            if (i < j) 
                a[j--] = a[i];
        }
        a[i] = key;
    }
    return i;
}

int CheckMoreThanHalf(vector<int> &numbers, int target) {
    if (target == -1) return 0;
    int times = 0;
    int thres_hold = numbers.size() / 2;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == target) 
            times++;
        if (times > thres_hold) 
            return target;
    }
    return 0;
}

int MoreThanHalfNumSolution3(vector<int> numbers) {
    int len = numbers.size();
    if (len <= 0) return 0;
    int l = 0, r = len - 1, pos, target;
    int k = len / 2;
    pos = Partition(numbers, l, r);
    while (k != pos) {
        if (pos > k) {
            r = pos - 1;
            pos = Partition(numbers, l, r);
        } else {
            l = pos + 1;
            pos = Partition(numbers, l, r);
        }
    }
    target = numbers[pos];
    return CheckMoreThanHalf(numbers, target);
}

int main() {
    // 测试用例: {99,99}
    string str_input;
    vector<int> arr;
    cin >> str_input;
    const char *split = "{,}";
    char *s_input = (char *)str_input.c_str();
    char *p = strtok(s_input, split);
    int num;
    while (p != NULL) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }
    cout << MoreThanHalfNumSolution(arr) << endl;
    cout << MoreThanHalfNumSolution2(arr) << endl;
    cout << MoreThanHalfNumSolution3(arr) << endl;
    return 0;
}