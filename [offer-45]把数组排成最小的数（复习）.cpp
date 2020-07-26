/**
 * Creation         :       2019.04.22 13:59
 * Last Reversion   :       2019.04.22 14:06
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * PrintMinNumber(把数组排成最小的数)
 * 题目描述
 *    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有
 * 数字中最小的一个。例如输入数组 {3，32，321} ，则打印出这三个数字能排成的最小数字为321323。
 * 思想：
 *    (1) 使用全排列
 *    (2) 先升序排序，然后再将其连接起来
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;


/* ----------------------------- 方法一：使用全排列 ------------------------------- */
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void FullyArrange(vector<int> &data, int index, string &min_val, bool &first_time) {
    if (index == data.size()) {
        string s = "";
        for (int i = 0; i < data.size(); i++) {
            s += to_string(data[i]);
        }
        // 更新最小值
        if (first_time) {
            min_val = s;
            first_time = false;
        }
        if (min_val > s)
            min_val = s;
    } else {
        for (int j = index; j < data.size(); j++) {
            Swap(data[index], data[j]);
            FullyArrange(data, index + 1, min_val, first_time);
            Swap(data[index], data[j]);
        }
    }
}

string PrintMinNumber(vector<int> numbers) {
    if (numbers.size() == 0)
        return "";
    string min_val = "";
    bool first_time = true;
    FullyArrange(numbers, 0, min_val, first_time);
    return min_val;
}

/* ----------------------------- 方法二：使用数值规律 ------------------------------- */
/*
  对vector容器内的数据进行排序，按照 将a和b转为string后
  按 a＋b < b+a，则 a 排在在前的规则排序,
  如 2 21 因为 212 < 221 所以 排序后为 21 2 
  to_string() 可以将int 转化为string
*/
static bool cmp(int a, int b) {
    string A = "";
    string B = "";
    A += to_string(a);      // 注意 to_string 是C++11的特性
    A += to_string(b);
    B += to_string(b);
    B += to_string(a);
    return A < B;
}

string PrintMinNumber2(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}


int main() {
    string str;
    vector<int> arr;
    cin >> str;
    const char *split = "{,，}";
    char *str_input = (char*)str.c_str();
    char *p = strtok(str_input, split);
    int num;
    while (p != NULL) {
        sscanf(p, "%d", &num);
        arr.push_back(num);
        p = strtok(NULL, split);
    }
    cout << PrintMinNumber(arr) << endl << endl;;
    return 0;
}