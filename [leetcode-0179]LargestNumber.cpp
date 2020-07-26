/**
 * Creation         :       2019.07.09 15:01
 * Last Reversion   :       2019.07.09 16:15
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
largestNumber(最大数)
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:
输入: [10,2]
输出: 210

示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void FullyArrange(vector<int> &data, int index, string &max_val,
                  bool &first_time) {
    if (index == data.size()) {
        string s = "";
        for (int i = 0; i < data.size(); i++) {
            s += to_string(data[i]);
        }
        // 更新最大值
        if (first_time) {
            max_val = s;
            first_time = false;
        }
        if (max_val < s) max_val = s;
    } else {
        for (int j = index; j < data.size(); j++) {
            Swap(data[index], data[j]);
            FullyArrange(data, index + 1, max_val, first_time);
            Swap(data[index], data[j]);
        }
    }
}

/**
 * 方法一：全排列 （超时）不好
 */ 
string largestNumber(vector<int> &nums) {
    if (nums.size() == 0) return "";
    string max_val = "";
    bool first_time = true;
    FullyArrange(nums, 0, max_val, first_time);
    return max_val;
}


/**
  对vector容器内的数据进行排序，按照 将a和b转为string后
  按 a＋b < b+a，则 a 排在在前的规则排序,
  如 2 21 因为 212 < 221 所以 排序后为 21 2 
  to_string() 可以将int 转化为string
 */ 
static bool cmp(int a, int b) {
    string A = "";
    string B = "";
    A += to_string(a);
    A += to_string(b);
    B += to_string(b);
    B += to_string(a);
    return A > B;
}

/**
 * 处理字符串前面的0
 */ 
string RemovePreZero(string data) {
    int count = 0;
    int len = data.size();
    while (data[count] == '0') {
        count++;
    }
    return count == len ? "0" : data.substr(count, len-count);
}

/**
 * 方法二：先将数字进行降序排序，然后再数字拼接起来即可
 */ 
string largestNumberII(vector<int> &nums) {
    if (nums.size() == 0) return "";
    string res = "";
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size(); i++) {
        res += to_string(nums[i]);
    }
    res = RemovePreZero(res);
    return res;
}

int main() {
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // vector<int> nums = {0, 0, 0, 0};
    vector<int> nums = {0, 0, 0, 1};
    cout << largestNumberII(nums) << endl;
    cout << largestNumber(nums) << endl;
    return 0;
}
