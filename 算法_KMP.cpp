/**
 * Creation         :       2019.07.01 14:38
 * Last Reversion   :       2019.07.01 14:38
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
 * KMP 算法
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * 计算模式串的next数组
 * @param substr:   模式串
 * @param next[]:   next数组
 * 思想：（自己手动结合md笔记例题好好Debug一遍就理解了）
 */ 
void GetNext(string substr, int next[]) {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < substr.length()) {               
        if (j == -1 || substr[i] == substr[j]) {    // 若 j==-1，或者该字符匹配时，则i,j都后移一位
            i++;
            j++;
            next[i] = j;
        } else {            // 若 j!=-1，或者该字符不匹配时，此时，substr[i]即与substr[next[j]]进行比较
            j = next[j];
        }
    }
}

/**
 * KMP算法
 * @param str:      主串
 * @param substr:   模式串
 */ 
int KMP(string str, string substr, int next[]) {
    int i = 0, j = 0;
    while (i < str.length() && j < (int)substr.length()) {
        if (j == -1 || str[i] == substr[j]) {   // 字符匹配，或者j == -1，这个是由next数组产生的
            i++;
            j++;
        } else {                                // 字符不匹配
            j = next[j];
        }
    }
    if (j == substr.length())                   // 匹配成功，返回主串开始匹配的索引
        return i - substr.length();
    else                                        // 匹配不成功
        return -1;
}

int main() {
    // string str = "ababababca";
    // string strsub = "abababca";
    string str = "hello";
    string strsub = "ll";
    // 计算模式串的next数组
    int *next = new int[strsub.size()];
    GetNext(strsub, next);
    for (int i = 0; i < strsub.size(); i++) {
        cout << next[i];
    }
    cout << endl;

    // 使用KMP算法进行匹配
    int start_idx = KMP(str, strsub, next);
    int end_idx = start_idx + strsub.size();
    for (int i = start_idx; i < end_idx; i++) {
        cout << str[i];
    }
    cout << endl;
    delete [] next;
    return 0;
}