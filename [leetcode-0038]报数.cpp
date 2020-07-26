/**
 * Creation         :       2019.05.08 09:00
 * Last Reversion   :       2019.05.08 09:53
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * countAndSay(报数)
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

/**
 * 获取当前的str
 */ 
string curSayString(string str) {
    string res_str = "";
    int flag;
    for (int i = 0; i < str.size(); ) {
        char key = str[i];
        int key_num = 1;
        flag = 0;
        while (i+1 < str.size() && str[i+1] == key) {
            key_num++;
            flag = 1;
            i++;
        }
        res_str += to_string(key_num);
        res_str += key;
        i++;
    }
    return res_str;
}

string countAndSay(int n) {
    string cur_str = "1";
    for (int i = 1; i < n; i++) {
        cur_str = curSayString(cur_str);
    }
    return cur_str;
}

int main() {
    int n;
    cin >> n;
    cout << countAndSay(n);    
    return 0;
}
