/**
 * Creation         :       2019.04.13 11:25
 * Last Reversion   :       2019.04.13 11:47
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * Permutation(字符串的排列)
 * 题目描述
 *    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
 * 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> res;

/**
 * 交换两个字符串
 */ 
void Swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

/*
思路：递归法，问题转换为先固定第一个字符，求剩余字符的排列；求剩余字符排列时跟原问题一样。
(1) 遍历出所有可能出现在第一个位置的字符（即：依次将第一个字符同后面所有字符交换）；
(2) 固定第一个字符，求后面字符的排列（即：在第1步的遍历过程中，插入递归进行实现）。
需要注意的几点：
(1) 先确定递归结束的条件，例如本题中可设begin == str.size() - 1; 
(2) 形如 aba 或 aa 等特殊测试用例的情况，vector在进行push_back时是不考虑重复情况的，需要自行控制；
(3) 输出的排列可能不是按字典顺序排列的，可能导致无法完全通过测试用例，考虑输出前排序，或者递归之后取消复位操作。
*/
void FullyArrange(string str, int index, int str_len) {
    if (index == str_len && find(res.begin(), res.end(), str) == res.end()) {   // 注意：如果res中不存在str，才添加；避免aa和aa重复添加的情况
        res.push_back(str);
    } else {
        for (int j = index; j < str_len; j++) {
            Swap(&str[index], &str[j]);
            FullyArrange(str, index + 1, str_len);
            Swap(&str[index], &str[j]);
        }
    }
}

vector<string> Permutation(string str) {
    if (str.empty())
        return res;
    FullyArrange(str, 0, str.size());
    sort(res.begin(), res.end());
    return res;
}

int main() {
    string str;
    cin >> str;
    res = Permutation(str);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}