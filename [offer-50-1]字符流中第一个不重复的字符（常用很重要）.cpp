/**
 * Creation         :       2019.04.29 11:17
 * Last Reversion   :       2019.04.29 11:27
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * FirstAppearingOnce(字符流中第一个不重复的字符)
 * 题目描述
 *    请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
 * 第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 如果当前字符流没有存在出现一次的字符，返回#字符。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define INF 0x7fffffff

string str;
vector<int> char_num(256, 0);

/**
 * Insert one char from stringstream
 */ 
void Insert(char ch) {
    str += ch;
    char_num[ch]++;
}

/**
 * return the first appearence once char in current stringstream
 */ 
char FirstAppearingOnce() {
    for (int i = 0; i < str.size(); i++) {
        if (char_num[str[i]] == 1)
            return str[i];
    }
    return '#';
}

int main() {
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) 
        Insert(input[i]);
    cout << FirstAppearingOnce();
    return 0;
}