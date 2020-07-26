/**
 * Creation         :       2019.04.29 10:00
 * Last Reversion   :       2019.04.29 11:10
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FirstNotRepeatingChar(第一个只出现一个的字符)
 * 题目描述
 *    在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次
 * 的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define INF 0x7fffffff

/**
 * 方法一：
 *    使用map进行存储，并用str[i]做为下标访问，找第一个次数为1的，这样就没有用排序的结构
 */ 
int FirstNotRepeatingCharII(string str) {
    // 将字符存储与map中，统计每个字符出现的次数
    map<char, int> char_num;
    for (int i = 0; i < str.size(); i++) {
        char_num[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++) {
        if (char_num[str[i]] == 1)
            return i;
    }
    return -1;
}

/**
 * 方法二： （这种方法，脑袋里一定要印象深刻才行！）
 *    自己建立一个Hash表，下标为ASCII码，值为次数。字符char占一个字节，8个bit位，
 * 因此总共有256种可能。于是可以创建一个长度为256的数字，每个字母根据其ASCII码作为
 * 数组的下标，出现的次数为值。第一次遍历进行存储，第二次遍历即可找到次数为1的。
 * 时间复杂度为：　O(n)
 */ 
int FirstNotRepeatingCharIII(string str) {
    vector<int> char_num(256, 0);
    for (int i = 0; i < str.size(); i++) {
        char_num[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++) {
        if (char_num[str[i]] == 1)
            return i;
    }
    return -1;
}

int main() {
    string str;
    cin >> str;
    cout << FirstNotRepeatingCharIII(str);
    return 0;
}